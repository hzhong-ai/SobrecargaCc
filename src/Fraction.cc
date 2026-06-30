#include "Fraction.h"

#include <iostream>
#include <numeric>
#include <stdexcept>

Fraction::Fraction(int numerator, int denominator)
  : numerator(numerator), denominator(denominator) {
  if(denominator == 0)
    throw std::invalid_argument("denominator cannot be zero");

  normalize();
}

Fraction::Fraction(int numerator)
  : Fraction(numerator, 1) {
}

int Fraction::num() const {
  return numerator;
}

int Fraction::den() const {
  return denominator;
}

void Fraction::normalize(){
  // 1. Si denominator < 0, mover el signo al numerador.
  if (denominator < 0){
    numerator *= -1; 
    denominator *= -1;
  }
  // 2. Usar std::gcd para reducir numerator y denominator.
  int g = std::gcd(std::abs(numerator), denominator); //std::gcd( , ) falla con numeros negativos
  numerator /= g;
  denominator /=g;
}

Fraction& Fraction::operator+=(const Fraction& other){
  //fraction es this, other es con quien operamos (a , b) other = b
  numerator = numerator * other.denominator + other.numerator * denominator;
  denominator = denominator * other denominator;
  normalize();
  return *this;
}

Fraction& Fraction::operator-=(const Fraction& other){
  numerator = numerator * other.denominator - other.numerator * denominator;
  denominator = denominator * other.denominator;
  normalize();
  return *this;
}

Fraction operator+(Fraction a, const Fraction& b){
  a += b;
  return a;
}

Fraction operator-(Fraction a, const Fraction& b){
  a -= b;
  return a;
}

Fraction operator*(const Fraction& a, const Fraction& b){
  return Fraction(a.num() * b.num(), a.den() * b.den());
}

Fraction operator/(const Fraction& a, const Fraction& b){
  if (b.num() == 0)
      throw std::invalid_argument("division por cero no esta definida");
  return Fraction(a.num() * b.den(), a.den() * b.den());
}

bool operator==(const Fraction& a, const Fraction& b){
  // TODO: implementar igualdad.
  (void)a;
  (void)b;
  return false;
}

bool operator!=(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator==.
  (void)a;
  (void)b;
  return false;
}

bool operator<(const Fraction& a, const Fraction& b){
  // TODO: implementar usando productos cruzados.
  (void)a;
  (void)b;
  return false;
}

bool operator<=(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator< y operator==.
  (void)a;
  (void)b;
  return false;
}

bool operator>(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator<.
  (void)a;
  (void)b;
  return false;
}

bool operator>=(const Fraction& a, const Fraction& b){
  // TODO: implementar usando operator<.
  (void)a;
  (void)b;
  return false;
}

std::ostream& operator<<(std::ostream& os, const Fraction& f){
  // TODO: imprimir con el formato numerador/denominador.
  (void)f;
  return os;
}

std::istream& operator>>(std::istream& is, Fraction& f){
  // TODO: leer con el formato numerador/denominador.
  // Si la entrada es invalida, marcar failbit y no modificar f.
  (void)f;
  return is;
}
