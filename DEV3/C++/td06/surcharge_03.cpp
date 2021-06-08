///*!
// * \file surcharge_03.cpp
// * \brief surcharge de fonctions
// */
//#include <iostream>

//void f(short) {
//    std::cout << "f(short)" << std::endl;
//}

//void f(double) {
//    std::cout << "f(double)" << std::endl;
//}

//int main() {
//    f(3); // déjà déclaré et ne sait pas lequel choisir vu qu'il faut le caster en double ou short
//    f(4.5); // f(double)
//    f(true); // déjà déclaré et ne sait pas lequel choisir vu qu'il faut le caster en double ou short
//    f(3LL); // déjà déclaré et ne sait pas lequel choisir vu qu'il faut le caster en double ou short
//    f('T'); // // déjà déclaré et ne sait pas lequel choisir vu qu'il faut le caster en double ou short
//    f(.3F); // f(double)
//    f(5U); // // déjà déclaré et ne sait pas lequel choisir vu qu'il faut le caster en double ou short
//    short s {44};
//    f(s); // f(short)
//    f(2e-2L); // déjà déclaré et ne sait pas lequel choisir vu qu'il faut le caster en double ou short
//}
