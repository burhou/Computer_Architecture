#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IPS 100

// �ˬd�Ӭq�O�_�����Ī� IP �q
bool isValidSegment(const char *s, int start, int end) {
    if (start > end) return false;

    // �ˬd�e�� 0
    if (s[start] == '0' && start != end) return false;

    // �ন�ƭȨ��ˬd�d�� 0~255
    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
        num = num * 10 + (s[i] - '0');
    }
    return num >= 0 && num <= 255;
}

// �N��쪺���� IP �[�J���G�}�C
void addIP(char **result, int *returnSize, const char *s, int p1, int p2, int p3) {
    char ip[16]; // IP �̦h���׬� 15�]�]�A�I�M�פ�š^
    snprintf(ip, sizeof(ip), "%.*s.%.*s.%.*s.%s",
             p1, s, p2 - p1, s + p1, p3 - p2, s + p2, s + p3);
    result[(*returnSize)++] = strdup(ip);
}

// �^���k�M��Ҧ��i�઺ IP ��}
void backtrack(char **result, int *returnSize, const char *s, int len, int start, int dots, int positions[]) {
    if (dots == 3) { // �w���J 3 ���I
        if (isValidSegment(s, start, len - 1)) { // �̫�@�q�ݦ���
            addIP(result, returnSize, s, positions[0], positions[1], positions[2]);
        }
        return;
    }

    // �M���C�ӥi�઺�����I�]�̦h 3 �Ӧr���^
    for (int i = start; i < len && i < start + 3; ++i) {
        if (isValidSegment(s, start, i)) { // �T�{���q����
            positions[dots] = i + 1; // �O�s�I����m
            backtrack(result, returnSize, s, len, i + 1, dots + 1, positions); // �~�����
        }
    }
}

// �D��ơG�ǤJ�r��æ^�ǩҦ����Ī� IP ��}
char **restoreIpAddresses(char *s, int *returnSize) {
    char **result = malloc(sizeof(char *) * MAX_IPS); // �x�s���G
    *returnSize = 0;
    int len = strlen(s);
    if (len < 4 || len > 12) return result; // ���פ��ūh��^�ŵ��G

    int positions[3]; // �O�s�C���I����m
    backtrack(result, returnSize, s, len, 0, 0, positions); // �}�l�^��
    return result;
}

// �ͦ��H���Ʀr��
void generateRandomString(char *s, int len) {
    for (int i = 0; i < len; i++) {
        s[i] = '0' + rand() % 10; // �ͦ� '0' �� '9' ���H���Ʀr
    }
    s[len] = '\0'; // �[�W�פ��
}

// ���ը��
int main() {
    srand(7); // ��l���H���ƥͦ���
    int returnSize;

    // �ͦ��ô��դT���H�����
    for (int i = 0; i < 3; i++) {
        int len = 4 + rand() % 9; // �H���ͦ����� 4~12
        char s[len + 1]; // �פ�� '\0'
        generateRandomString(s, len);

        printf("Test %d - Random Input: %s\n", i + 1, s);
        char **ips = restoreIpAddresses(s, &returnSize);

        if (returnSize == 0) {
            printf("No valid IP addresses found.\n");
        } else {
            printf("Valid IP addresses:\n");
            for (int j = 0; j < returnSize; ++j) {
                printf("%s\n", ips[j]);
                free(ips[j]); // ����O����
            }
        }
        free(ips); // ���񵲪G�}�C
        printf("\n");
    }

    return 0;
}
