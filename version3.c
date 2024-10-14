#include <stdio.h>
#include <stdbool.h>

#define MAX_IPS 100
#define MAX_IP_LENGTH 16 // IP address length: 15 characters + 1 null terminator

int returnSize;
char *testCases[] = {
        "25016247489",
        "12539220",
        "524816033"
    };
char result[MAX_IPS][MAX_IP_LENGTH]; // 預先分配儲存 IP 的陣列
int main() {

    for (int t = 0; t < 3; t++) {
        char *s = testCases[t];
        printf("Random Input: %s\n", s);
        returnSize = 0;

        int len = 0;
        while (s[len] != '\0') {
            len++;
        }
        if (len < 4 || len > 12) {
            printf("No valid IP addresses found.\n\n");
            continue; // 無效長度直接返回
        }

        // 生成 IP 地址的邏輯
        for (int i = 1; i < len && i <= 3; i++) { // 第一段
            // 檢查第一段是否有效
            if (s[0] == '0' && i > 1) continue; // 防止前導 0
            int num1 = 0;
            for (int j = 0; j < i; j++) num1 = num1 * 10 + (s[j] - '0');
            if (num1 > 255) continue;
            int p1 = i; // 第一段的結束位置

            for (int j = p1 + 1; j < len && j <= p1 + 3; j++) { // 第二段
                // 檢查第二段是否有效
                if (s[p1] == '0' && j > p1 + 1) continue; // 防止前導 0
                int num2 = 0;
                for (int k = p1; k < j; k++) num2 = num2 * 10 + (s[k] - '0');
                if (num2 > 255) continue;
                int p2 = j; // 第二段的結束位置

                for (int k = p2 + 1; k < len && k <= p2 + 3; k++) { // 第三段
                    // 檢查第三段是否有效
                    if (s[p2] == '0' && k > p2 + 1) continue; // 防止前導 0
                    int num3 = 0;
                    for (int l = p2; l < k; l++) num3 = num3 * 10 + (s[l] - '0');
                    if (num3 > 255) continue;
                    int p3 = k; // 第三段的結束位置

                    // 第四段
                    if (p3 < len) {
                        if (s[p3] == '0' && p3 + 1 < len) continue; // 防止前導 0
                        int num4 = 0;
                        for (int l = p3; l < len; l++) num4 = num4 * 10 + (s[l] - '0');
                        if (num4 > 255) continue; // 檢查第四段是否有效

                        // 生成有效的 IP 地址
                        char *ip = result[returnSize];
                        int index = 0;
                        for (int j = 0; j < p1; j++) ip[index++] = s[j];
                        ip[index++] = '.';
                        for (int j = p1; j < p2; j++) ip[index++] = s[j];
                        ip[index++] = '.';
                        for (int j = p2; j < p3; j++) ip[index++] = s[j];
                        ip[index++] = '.';
                        for (int j = p3; j < len; j++) ip[index++] = s[j];
                        ip[index] = '\0'; // 結尾符號
                        returnSize++;
                    }
                }
            }
        }

        if (returnSize == 0) {
            printf("No valid IP addresses found.\n\n");
        } else {
            printf("Valid IP addresses:\n");
            for (int j = 0; j < returnSize; ++j) {
                printf("%s\n", result[j]);
            }
            printf("\n");
        }
    }

    return 0;
}
