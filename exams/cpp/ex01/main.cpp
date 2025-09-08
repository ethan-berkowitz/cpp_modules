#include "Warlock.hpp"
#include "Dummy.hpp"
#include "Fwoosh.hpp"
#include "ASpell.hpp"
#include "ATarget.hpp"

int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();
  Fwoosh* fwoosh2 = new Fwoosh();
  Fwoosh* fwoosh3 = new Fwoosh();

  richard.learnSpell(fwoosh);
  richard.learnSpell(fwoosh2);
  richard.learnSpell(fwoosh3);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);
  richard.launchSpell("Fwoosh2", bob);
  richard.launchSpell("Fwoosh3", bob);

  std::cout << "OTHER---------------\n";

  richard.forgetSpell("Fwoosh");
  richard.forgetSpell("Fwoosh2");
  richard.forgetSpell("Fwoosh3");
  richard.forgetSpell("Fwoosh4");
  richard.launchSpell("Fwoosh", bob);
}
