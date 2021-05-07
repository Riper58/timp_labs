#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            cipherText.front() = towlower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout<<L"key="<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        wcerr<<"Error: "<<e.what()<<endl;
    }
}
int main(int argc, char **argv)
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"ПРИВЕТ",L"ЭХО");
    check(L"ПРИВЕТ",L"");
    check(L"ПРИВЕТ",L"323");
    check(L"ПРИВЕТ1",L"ЭХО");
    check(L"ПрИВЕт",L"ЭХО");
    check(L"",L"ЭХО");
    check(L"ПРИВЕТ",L"ЭХО",true);
    return 0;
}
