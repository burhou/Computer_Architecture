#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_IPS 100
#define MAX_IP_LENGTH 16 // IP address length: 15 characters + 1 null terminator

// �p��r����ת���� (���N strlen)
static inline int stringLength(const char *s) {
    int length = 0;
    while (s[length] != '\0') {
        length++;
    }
    return length;
}

// �N����ন�r��A�æ^���ഫ�᪺����
static inline int intToString(int num, char *buffer) {
    int length = 0;
    if (num == 0) {
        buffer[length++] = '0';
    } else {
        char temp[4]; // IP segment�̦h�T��ơA�~�[�@�� '\0'
        int i = 0;
        while (num > 0) {
            temp[i++] = (num % 10) + '0';
            num /= 10;
        }
        // ���� temp�A��J buffer
        while (i > 0) {
            buffer[length++] = temp[--i];
        }
    }
    buffer[length] = '\0'; // �[�W�r�굲���Ÿ�
    return length;
}

// �N��쪺���� IP �[�J���G�}�C
static inline void addIP(char result[MAX_IPS][MAX_IP_LENGTH], int *returnSize, const char *s, int p1, int p2, int p3) {
    char *ip = result[*returnSize]; // ���o��e�x�s��m������
    int index = 0;

    // �N�|�q IP �̧ǲզ��r��
    for (int i = 0; i < p1; ++i) ip[index++] = s[i];
    ip[index++] = '.';

    for (int i = p1; i < p2; ++i) ip[index++] = s[i];
    ip[index++] = '.';

    for (int i = p2; i < p3; ++i) ip[index++] = s[i];
    ip[index++] = '.';

    for (int i = p3; s[i] != '\0'; ++i) ip[index++] = s[i];

    ip[index] = '\0'; // �[�W�r�굲���Ÿ�
    (*returnSize)++;
}

// �ˬd�Ӭq�O�_�����Ī� IP �q
static inline bool isValidSegment(const char *s, int start, int end) {
    if (start > end) return false;

    // �ˬd�e�� 0 (���׶W�L 1 �B�Ĥ@�Ӧr���O '0' �ɵL��)
    if (s[start] == '0' && start != end) return false;

    int num = 0;
    for (int i = start; i <= end; i++) {
        if (s[i] < '0' || s[i] > '9') return false;
        num = num * 10 + (s[i] - '0');
    }
    return num <= 255;
}

// �^���k�M��Ҧ��i�઺ IP ��}
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

// �D��ơG�ǤJ�r��æ^�ǩҦ����Ī� IP ��}
static inline void restoreIpAddresses(char *s, int *returnSize, char result[MAX_IPS][MAX_IP_LENGTH]) {
    *returnSize = 0;
    int len = stringLength(s); // �ϥΦۭq�� stringLength ���
    if (len < 4 || len > 12) return; // �L�Ī��ת�����^

    int positions[3];
    backtrack(result, returnSize, s, len, 0, 0, positions);
}

// ���ը��
int main() {
    int returnSize;

    // �ϥδ��Ѫ����ո��
    char *testCases[] = {
        "25016247489",
        "12539220",
        "524816033"
    };

    char result[MAX_IPS][MAX_IP_LENGTH]; // �w�����t�x�s IP ���}�C

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
