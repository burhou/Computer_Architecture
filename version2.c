#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_IPS 100
#define MAX_IP_LENGTH 16 // IP address length: 15 characters + 1 null terminator

// 計算字串長度的函數 (取代 strlen)
static inline int stringLength(const char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

// 將整數轉成字串，並回傳轉換後的長度
static inline int intToString(int num, char *buffer) {
    int length = 0;
    if (num == 0) {
        buffer[length++] = '0';
    } else {
        char temp[4]; // IP segment最多三位數，外加一個 '\0'
        int i = 0;
        while (num > 0) {
            temp[i++] = (num % 10) + '0';
            num /= 10;
        }
        // 反轉 temp，放入 buffer
        while (i > 0) {
            buffer[length++] = temp[--i];
        }
    }
    buffer[length] = '\0'; // 加上字串結尾符號
    return length;
}

// 將找到的有效 IP 加入結果陣列
static inline void addIP(char result[MAX_IPS][MAX_IP_LENGTH], int *returnSize, const char *s, int p1, int p2, int p3) {
    char *ip = result[*returnSize]; // 取得當前儲存位置的指標
    int index = 0;

    // 將四段 IP 依序組成字串
    for (int i = 0; i < p1; ++i) ip[index++] = s[i];
    ip[index++] = '.';

    for (int i = p1; i < p2; ++i) ip[index++] = s[i];
    ip[index++] = '.';

    for (int i = p2; i < p3; ++i) ip[index++] = s[i];
    ip[index++] = '.';

    for (int i = p3; s[i] != '\0'; ++i) ip[index++] = s[i];

    ip[index] = '\0'; // 加上字串結尾符號
    (*returnSize)++;
}

// 檢查該段是否為有效的 IP 段
static inline bool isValidSegment(const char *s, int start, int end) {
    if (start > end) return false;

    // 檢查前導 0 (長度超過 1 且第一個字元是 '0' 時無效)
    if (s[start] == '0' && start != end) return false;

    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
        num = num * 10 + (s[i] - '0');
    }
    return num <= 255;
}

// 回溯法尋找所有可能的 IP 位址
static inline void backtrack(char result[MAX_IPS][MAX_IP_LENGTH], int *returnSize, const char *s, int len, int start, int dots, int positions[]) {
    if (dots == 3) {
        if (isValidSegment(s, start, len - 1)) {
            addIP(result, returnSize, s, positions[0], positions[1], positions[2]);
        }
        return;
    }

    for (int i = start; i < len && i < start + 3; ++i) {
        if (isValidSegment(s, start, i)) {
            positions[dots] = i + 1;
            backtrack(result, returnSize, s, len, i + 1, dots + 1, positions);
        }
    }
}

// 主函數：傳入字串並回傳所有有效的 IP 位址
static inline void restoreIpAddresses(char *s, int *returnSize, char result[MAX_IPS][MAX_IP_LENGTH]) {
    *returnSize = 0;
    int len = stringLength(s); // 使用自訂的 stringLength 函數
    if (len < 4 || len > 12) return; // 無效長度直接返回

    int positions[3];
    backtrack(result, returnSize, s, len, 0, 0, positions);
}

// 測試函數
int main() {
    int returnSize;

    // 使用提供的測試資料
    char *testCases[] = {
        "25016247489",
        "12539220",
        "524816033"
    };

    char result[MAX_IPS][MAX_IP_LENGTH]; // 預先分配儲存 IP 的陣列

    for (int i = 0; i < 3; i++) {
        char *s = testCases[i];
        printf("Test %d - Random Input: %s\n", i + 1, s);

        restoreIpAddresses(s, &returnSize, result);

        if (returnSize == 0) {
            printf("No valid IP addresses found.\n");
        } else {
            printf("Valid IP addresses:\n");
            for (int j = 0; j < returnSize; ++j) {
                printf("%s\n", result[j]);
            }
        }
        printf("\n");
    }

    return 0;
}
