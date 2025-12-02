#include <iostream>
#include <string>

// A feladatban megadott struktúra
struct account {
    std::string accountNo;
    std::string email;
    std::string mobile;
    std::string taxNo;
    std::string taxId;
    account* next;
};

// Segédfüggvény: beszúrás a lista ELEJÉRE (a feladat példája ezt használja)
account* insertFirst(account* anchor,
                     const std::string& accountNo,
                     const std::string& email,
                     const std::string& mobile,
                     const std::string& taxNo,
                     const std::string& taxId) {
    account* newNode = new account{accountNo, email, mobile, taxNo, taxId, anchor};
    return newNode;
}

// !!! A FELADAT SZERINTI FÜGGVÉNY !!!
// Hozzáfűzi a lista végéhez az új elemet, ha MINDEN azonosító egyedi.
account* append(account* anchor,
                std::string accountNo,
                std::string email,
                std::string mobile,
                std::string taxNo,
                std::string taxId) 
{
    // 1) Először ellenőrizzük, hogy bármelyik azonosító szerepel-e már a listában
    account* p = anchor;
    while (p != nullptr) {
        if (p->accountNo == accountNo ||
            p->email     == email     ||
            p->mobile    == mobile    ||
            p->taxNo     == taxNo     ||
            p->taxId     == taxId) {
            // Már létezik valamelyik azonosító -> nem szúrunk be semmit
            return anchor;
        }
        p = p->next;
    }

    // 2) Ha minden egyedi, létrehozunk egy új elemet
    account* uj = new account {accountNo, email, mobile, taxNo, taxId, nullptr};

    // 3) Ha a lista eddig üres volt
    if (anchor == nullptr) {
        return uj;  // az új elem lesz a horgony
    }

    // 4) Egyébként elmegyünk a lista VÉGÉRE és odafűzzük
    account* last = anchor;
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = uj;

    // Mindig a lista elejével térünk vissza
    return anchor;
}

// Segédfüggvény: lista kiírása
void print(const account* anchor) {
    const account* p = anchor;
    while (p != nullptr) {
        std::cout << p->accountNo << '/'
                  << p->email     << '/'
                  << p->mobile    << '/'
                  << p->taxNo     << '/'
                  << p->taxId     << '\n';
        p = p->next;
    }
}

// Segédfüggvény: memória felszabadítása
void freeMem(account* anchor) {
    while (anchor != nullptr) {
        account* tmp = anchor;
        anchor = anchor->next;
        delete tmp;
    }
}

// Teszt a feladatban megadott példával
int main() {
    account* a1 = nullptr;

    a1 = insertFirst(a1, "33333333-33333333", "3@bank.hu", "+36 333-3333",
                     "33333333-3-33", "3333333333");
    a1 = insertFirst(a1, "22222222-22222222", "2@bank.hu", "+36 222-2222",
                     "22222222-2-22", "2222222222");
    a1 = insertFirst(a1, "11111111-11111111", "1@bank.hu", "+36 111-1111",
                     "11111111-1-11", "1111111111");

    // Új, teljesen egyedi elem hozzáfűzése a lista VÉGÉRE
    a1 = append(a1, "44444444-44444444", "4@bank.hu", "+36 444-4444",
                "44444444-4-44", "4444444444");

    print(a1);
    freeMem(a1);

    return 0;
}
