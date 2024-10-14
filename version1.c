#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IPS 100

// 檢查該段是否為有效的 IP 段
bool isValidSegment(const char *s, int start, int end) {
    if (start > end) return false;

    // 檢查前導 0
    if (s[start] == '0' && start != end) return false;

    // 轉成數值並檢查範圍 0~255
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
        num = num * 10 + (s[i] - '0');
    }
    return num >= 0 && num <= 255;
}

// 將找到的有效 IP 加入結果陣列
void addIP(char **result, int *returnSize, const char *s, int p1, int p2, int p3) {
    char ip[16]; // IP 最多長度為 15（包括點和終止符）
    snprintf(ip, sizeof(ip), "%.*s.%.*s.%.*s.%s",
             p1, s, p2 - p1, s + p1, p3 - p2, s + p2, s + p3);
    result[(*returnSize)++] = strdup(ip);
}

// 回溯法尋找所有可能的 IP 位址
void backtrack(char **result, int *returnSize, const char *s, int len, int start, int dots, int positions[]) {
    if (dots == 3) { // 已插入 3 個點
        if (isValidSegment(s, start, len - 1)) { // 最後一段需有效
            addIP(result, returnSize, s, positions[0], positions[1], positions[2]);
        }
        return;
    }

    // 遍歷每個可能的分割點（最多 3 個字元）
    for (int i = start; i < len && i < start + 3; ++i) {
        if (isValidSegment(s, start, i)) { // 確認此段有效
            positions[dots] = i + 1; // 保存點的位置
            backtrack(result, returnSize, s, len, i + 1, dots + 1, positions); // 繼續分割
        }
    }
}

// 主函數：傳入字串並回傳所有有效的 IP 位址
char **restoreIpAddresses(char *s, int *returnSize) {
    char **result = malloc(sizeof(char *) * MAX_IPS); // 儲存結果
    *returnSize = 0;
    int len = strlen(s);
    if (len < 4 || len > 12) return result; // 長度不符則返回空結果

    int positions[3]; // 保存每個點的位置
    backtrack(result, returnSize, s, len, 0, 0, positions); // 開始回溯
    return result;
}

// 生成隨機數字串
void generateRandomString(char *s, int len) {
    for (int i = 0; i < len; i++) {
        s[i] = '0' + rand() % 10; // 生成 '0' 到 '9' 的隨機數字
    }
    s[len] = '\0'; // 加上終止符
}

// 測試函數
int main() {
    srand(7); // 初始化隨機數生成器
    int returnSize;

    // 生成並測試三組隨機資料
    for (int i = 0; i < 3; i++) {
        int len = 4 + rand() % 9; // 隨機生成長度 4~12
        char s[len + 1]; // 終止符 '\0'
        generateRandomString(s, len);

        printf("Test %d - Random Input: %s\n", i + 1, s);
        char **ips = restoreIpAddresses(s, &returnSize);

        if (returnSize == 0) {
            printf("No valid IP addresses found.\n");
        } else {
            printf("Valid IP addresses:\n");
            for (int j = 0; j < returnSize; ++j) {
                printf("%s\n", ips[j]);
                free(ips[j]); // 釋放記憶體
            }
        }
        free(ips); // 釋放結果陣列
        printf("\n");
    }

    return 0;
}
