#include "LZespolona.hh"

Zespolona::Zespolona()
{
  Re =0;
  Im =0;
}

Zespolona::Zespolona(double & re, double & im)
{
  Re = re;
  Im = im;
}

double & Zespolona::GetRe()
{
  return Re;
}

double & Zespolona::GetIm()
{
  return Im;
}

Zespolona  Zespolona::operator + (const Zespolona & Skl1)const
{
  Zespolona  Wynik;

  Wynik.Re = Re + Skl1.Re;
  Wynik.Im = Im + Skl1.Im;
  return Wynik;
}

Zespolona  Zespolona::operator - (const Zespolona & Skl1)const
{
  Zespolona  Wynik;

  Wynik.Re = Re - Skl1.Re;
  Wynik.Im = Im - Skl1.Im;
  return Wynik;
}

Zespolona  Zespolona::operator * (const Zespolona & Skl1)const
{
  Zespolona  Wynik;

  Wynik.Re = Re*Skl1.Re - Im*Skl1.Im;
  Wynik.Im = Re*Skl1.Im + Skl1.Re*Im;

  return Wynik;
}

Zespolona Zespolona::operator / (const Zespolona & Skl1)const 
{
  Zespolona Wynik, Licznik;
  double Mianownik;

  Licznik = *this * Skl1.sprzezenie();
  Mianownik = pow(Skl1.modul(),2);

  if(Mianownik < E)
  {
    std::cerr << "Dzielenie przez zero" << std::endl;
    exit(0);
  }
  
  else
  {
    Wynik.Re = Licznik.Re/Mianownik;
    Wynik.Im = Licznik.Im/Mianownik;
    //std::cout << Wynik.Re << " " << Wynik.Im << "i" << std::endl;
    return Wynik;
  }
  

  
}

Zespolona Zespolona::sprzezenie()const
{
  Zespolona Wynik;
  if(Im < E && Im > -E)
    return *this;
  else
  {
    Wynik.Im = Im;
    return Wynik;
  }
}

double Zespolona::modul()const
{
  return sqrt(pow(Re, 2) + pow(Im, 2));
}

 bool Zespolona::operator == (const Zespolona & Skl1)const
 {
  if(Re == Skl1.Re && Im == Skl1.Im)
    return true;
  else
    return false;
 }

 bool Zespolona::operator != (const Zespolona & Skl1)const
 {
    return !(*this == Skl1);
 }

std::istream & operator >> (std::istream & str, Zespolona &in)
{
  char znak;
  str>>znak;

  if(znak != '(') {
    str.setstate(std::ios::failbit);
  }

  str>>in.GetRe();
  str>>in.GetIm();
  str>>znak;

  if(znak != 'i') {
    str.setstate(std::ios::failbit);
  }
    
  str>>znak;
  
  if(znak != ')') {
    str.setstate(std::ios::failbit);
  }
  return str;
}

std::ostream & operator << (std::ostream & str, Zespolona &out)
{
  str << "(" << out.GetRe();
  if(out.GetIm() >= 0)
    str << "+" << out.GetIm() << "i)";

  else
    str << out.GetIm() << "i)";
  
  return str;
}