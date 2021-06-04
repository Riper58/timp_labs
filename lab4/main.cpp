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
    wstring raz = L"...............................";
    check(L"ПРИВЕТ",L"ЭХО");
    wcout<<raz<<endl;
    check(L"ПРИВЕТ",L"");
    wcout<<raz<<endl;
    check(L"ПРИВЕТ",L"323");
    wcout<<raz<<endl;
    check(L"ПРИВЕТ1",L"ЭХО");
    wcout<<raz<<endl;
    check(L"ПрИВЕт",L"ЭХО");
    wcout<<raz<<endl;
    check(L"",L"ЭХО");
    wcout<<raz<<endl;
    check(L"ПРИВЕТ",L"ЭХО",true);
    wcout<<raz<<endl;
    return 0;
}