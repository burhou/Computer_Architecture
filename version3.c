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
char result[MAX_IPS][MAX_IP_LENGTH]; // �w�����t�x�s IP ���}�C
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
            continue; // �L�Ī��ת�����^
        }

        // �ͦ� IP �a�}���޿�
        for (int i = 1; i < len && i <= 3; i++) { // �Ĥ@�q
            // �ˬd�Ĥ@�q�O�_����
            if (s[0] == '0' && i > 1) continue; // ����e�� 0
            int num1 = 0;
            for (int j = 0; j < i; j++) num1 = num1 * 10 + (s[j] - '0');
            if (num1 > 255) continue;
            int p1 = i; // �Ĥ@�q��������m

            for (int j = p1 + 1; j < len && j <= p1 + 3; j++) { // �ĤG�q
                // �ˬd�ĤG�q�O�_����
                if (s[p1] == '0' && j > p1 + 1) continue; // ����e�� 0
                int num2 = 0;
                for (int k = p1; k < j; k++) num2 = num2 * 10 + (s[k] - '0');
                if (num2 > 255) continue;
                int p2 = j; // �ĤG�q��������m

                for (int k = p2 + 1; k < len && k <= p2 + 3; k++) { // �ĤT�q
                    // �ˬd�ĤT�q�O�_����
                    if (s[p2] == '0' && k > p2 + 1) continue; // ����e�� 0
                    int num3 = 0;
                    for (int l = p2; l < k; l++) num3 = num3 * 10 + (s[l] - '0');
                    if (num3 > 255) continue;
                    int p3 = k; // �ĤT�q��������m

                    // �ĥ|�q
                    if (p3 < len) {
                        if (s[p3] == '0' && p3 + 1 < len) continue; // ����e�� 0
                        int num4 = 0;
                        for (int l = p3; l < len; l++) num4 = num4 * 10 + (s[l] - '0');
                        if (num4 > 255) continue; // �ˬd�ĥ|�q�O�_����

                        // �ͦ����Ī� IP �a�}
                        char *ip = result[returnSize];
                        int index = 0;
                        for (int j = 0; j < p1; j++) ip[index++] = s[j];
                        ip[index++] = '.';
                        for (int j = p1; j < p2; j++) ip[index++] = s[j];
                        ip[index++] = '.';
                        for (int j = p2; j < p3; j++) ip[index++] = s[j];
                        ip[index++] = '.';
                        for (int j = p3; j < len; j++) ip[index++] = s[j];
                        ip[index] = '\0'; // �����Ÿ�
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
