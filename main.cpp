// ****************************************************************************
// Arquivo criado para estudo de conceitos C++ Moderno
// Autor - Mr. Grilo
// Data - Janeiro de 2021
// ****************************************************************************
// Inspiracoes e referencias podem ser encontradas em 
//
// Video do Straustrop  CppCon 2017: 
// Bjarne Stroustrup “Learning and Teaching Modern C++”
// https://www.youtube.com/watch?v=fX2W3nNjJIo
//
// https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md
// https://isocpp.org/blog/2015/09/bjarne-stroustrup-announces-cpp-core-guidelines
// https://en.cppreference.com/w/
// *****************************************************************************
// Glauco gosta desse link
// https://www.learncpp.com/
//
// *****************************************************************************

#include <iostream>
#include <typeindex>
#include <typeinfo>

int double_age(int age) {  // funcoes - passando argumento por valor
    return 2*age;          // Vide Cap. 10.2 do learncpp
}

void double_age_inplace_ptr(int* age) {  // funcoes - passando argumento por endereco
    *age = 2 * (*age);                   // Vide Cap. 10.3 do learncpp
}

void double_age_inplace_ref(int& age) {  // funcoes - passando argumento por referencia
    age = 2 * age;                       // Vide Cap. 10.3 do learncpp
}

int main(int argc, char* argv[]) {

    int age = 0; // 32bits // este igual NÃO É ATRIBUIÇÃO
                           // Chamado "copy initialization"
                           // Vide Cap. 1.4 do learncpp
    //int age;
    //age = 0; // aqui o igual é atribuição (assignment)
    
    age = 0b10; // binário
    
    age = 0x19; // hexadecimal
    std::cout << "Insert value for your age:" << age << std::endl;
    std::cin >> age;
    
    std::cout << "age é: " << age << std::endl;
    
    if (age < 16) {
        std::cout << "você não pode votar!" << std::endl;
    }
    else {
        std::cout << "você pode votar!" << std::endl;
    }
    
    int* ptr = &age;
    
    std::cout << "valor de ptr: " << ptr << std::endl;
    std::cout << "valor de *ptr: " << *ptr << std::endl;
    std::cout << "valor de &ptr: " << &ptr << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "valor de age: " << age << std::endl;
    std::cout << "valor de &age: " << &age << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    int age2{33};
    
    ptr = &age2;
    
    std::cout << "valor de ptr: " << ptr << std::endl;
    std::cout << "valor de *ptr: " << *ptr << std::endl;
    std::cout << "valor de &ptr: " << &ptr << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "valor de age: " << age << std::endl;
    std::cout << "valor de &age: " << &age << std::endl;
    
    std::cout << "valor de age2: " << age2 << std::endl;
    std::cout << "valor de &age2: " << &age2 << std::endl;
    
    std::cout << "age duplicada: " << double_age(age) << std::endl;
    std::cout << "age2 duplicada: " << double_age(age2) << std::endl;
    
    std::cout << "valor de age: " << age << std::endl;
    std::cout << "valor de age2: " << age2 << std::endl;
    
    std::cout << std::endl;
    
    double_age_inplace_ptr(&age);
    double_age_inplace_ptr(&age2);
    
    std::cout << "valor de age: " << age << std::endl;
    std::cout << "valor de age2: " << age2 << std::endl;
    
    //olha o escopo
    
    {
        int xablau = 10;
        std::cout << "xablau vale " << xablau << std::endl;
    }
    
    double xablau = 15;
    
    std::cout << "xablau vale " << xablau << std::endl;
    
    int coisa;
    
    int& ref_age = age; //alias
    
    std::cout << "atribuindo 68 para ref_age" << std::endl;
    
    ref_age = 68;
    
    std::cout << "valor de age: " << age << std::endl;
    
    double_age_inplace_ref(age);
    double_age_inplace_ref(age2);
    
    std::cout << "valor de age: " << age << std::endl;
    std::cout << "valor de age2: " << age2 << std::endl;
    
    int array[10] = {0, 1, 2, 30, 4, 5, 6, 7, 8, 9};
    
    std::cout << "o primeiro elemento de array é " << array[0] << std::endl;
    std::cout << "o último elemento de array é " << array[9] << std::endl;
    
    // For loop tradicional  "raiz"
    for(int i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }
    
    std::cout << std::endl;
    
    array[3] = 9;
    
    // Range-based for loop (since C++11)
    // https://en.cppreference.com/w/cpp/language/range-for
    for(int& i : array) {
        i = i*i;
        array[4] = -5;
        std::cout << i << " ";
    }
    
    std::cout << std::endl;
    
    for(int i = 0; i < 10; i++) {
        std::cout << array[i] << " ";
    }
    
    for(const auto& i : array) {
        std::cout << i << " ";
    }
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    auto coisa2 = 5; // 32 bit
    float coisa3 = (float)(coisa2/2);
    
    std::cout << 5/2 << std::endl;
    std::cout << 5./2 << std::endl;
    std::cout << coisa3 << std::endl;
    
    std::cout << std::endl;
    std::cout << std::endl;
    
    auto v0 = 2.f;
    auto v1 = 2.;
    auto v2 = 'a';
    auto v3 = 0x7f;
    
    auto& v0r = v0;
    auto& v1r = v1;
    auto& v2r = v2;
    auto& v3r = v3;
    
    auto* v0p = &v0;
    auto* v1p = &v1;
    auto* v2p = &v2;
    auto* v3p = &v3;
    
    std::cout << "v0 type: " << typeid(v0).name() << " size: " << sizeof(v0) << std::endl;
    std::cout << "v1 type: " << typeid(v1).name() << " size: " << sizeof(v1) << std::endl;
    std::cout << "v2 type: " << typeid(v2).name() << " size: " << sizeof(v2) << std::endl;
    std::cout << "v3 type: " << typeid(v3).name() << " size: " << sizeof(v3) << std::endl;
    
    std::cout << "v0r type: " << typeid(v0r).name() << " size: " << sizeof(v0r) << std::endl;
    std::cout << "v1r type: " << typeid(v1r).name() << " size: " << sizeof(v1r) << std::endl;
    std::cout << "v2r type: " << typeid(v2r).name() << " size: " << sizeof(v2r) << std::endl;
    std::cout << "v3r type: " << typeid(v3r).name() << " size: " << sizeof(v3r) << std::endl;
    
    std::cout << "v0p type: " << typeid(v0p).name() << " size: " << sizeof(v0p) << std::endl;
    std::cout << "v1p type: " << typeid(v1p).name() << " size: " << sizeof(v1p) << std::endl;
    std::cout << "v2p type: " << typeid(v2p).name() << " size: " << sizeof(v2p) << std::endl;
    std::cout << "v3p type: " << typeid(v3p).name() << " size: " << sizeof(v3p) << std::endl;
    
    return 0;
}
