//
// Created by zhangsiyu on 2021/2/24.
//

#ifndef TEST54_INDEX_CRYPT_H
#define TEST54_INDEX_CRYPT_H

int cache[1000] = {-1};

/*
 *  origin: the string to be encrypt
 *  originSize: length of origin string
 *  result: array that receives cipher code
 *  resultSize: length of result
 */
void encrypt(const char *origin, int originSize, int *result, int *resultSize) {
    *resultSize = originSize;
    char keys[] = "# abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789{}[]()<>+-*/\"\',.?;`~!@$%^&*_\\\n\t|";
    int k = 0;
    for (int i = 0; i < originSize; ++i) {
        if (keys[cache[origin[i]]] == origin[i]) {
            result[k++] = cache[origin[i]];
            continue;
        }
        for (int j = 0; j < strlen(keys); ++j) {
            if (keys[j] == origin[i]) {
                result[k++] = j;
                cache[origin[i]] = j;
                break;
            }
        }
    }
}

/*
 *  result: array contains cipher code
 *  resultSize: length of result
 *  str: the string that receives decrypted plain text
 *  strSize: length of str
 */
void decrypt(const int *result, const int resultSize, char *str, const int strSize) {
    if (strSize < resultSize) return;
    char keys[] = "# abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789{}[]()<>+-*/\"\',.?;`~!@$%^&*_\\\n\t|";
    for (int i = 0; i < resultSize; ++i) {
        str[i] = keys[result[i]];
    }
}

/*
 *  result: array contains cipher code
 *  resultSize: length of result
 *  testStr: the string that contains plain text
 *  testStrSize: length of testStr
 */
bool cmp(const int *result, const int resultSize, const char *testStr, const int testStrSize) {
    if (resultSize != testStrSize) return false;
    int testStrEnc[testStrSize];
    int k = 0;
    encrypt(testStr, testStrSize, testStrEnc, &k);
    for (int i = 0; i < k; ++i) {
        if (testStrEnc[i] != result[i]) return false;
    }
    return true;
}

#endif //TEST54_INDEX_CRYPT_H
