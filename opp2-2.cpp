#include <iostream>
using namespace std;

int countVowels(const char* p)
{
    int count = 0;
    while (*p != '\0')
    {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' ||
            *p == 'A' || *p == 'E' || *p == 'I' || *p == 'O' || *p == 'U')
        {
            count++;
        }
        p++;
    }
    return count;
}

int main()
{
    char str[200];
    cin.getline(str, 200);
    cout << countVowels(str) << endl;
    return 0;
}
