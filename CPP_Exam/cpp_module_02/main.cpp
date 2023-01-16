#include "Warlock.hpp"
#include "TargetGenerator.hpp"

int main()
{
  {
  // Warlock richard("Richard", "the Titled");

  // Dummy bob;
  // Fwoosh* fwoosh = new Fwoosh();

  // richard.learnSpell(fwoosh);

  // richard.introduce();
  // richard.launchSpell("Fwoosh", bob);

  // richard.forgetSpell("Fwoosh");
  // richard.launchSpell("Fwoosh", bob);
  // richard.launchSpell("Fwoosh", bob);
  // richard.launchSpell("Fwoosh", bob);
}
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  tarGen.forgetTargetType("Inconspicuous Red-brick Wall");
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

    richard.introduce();
  if(wall)
  {
    richard.launchSpell("Polymorph", *wall);
    richard.launchSpell("Fireball", *wall);
  }
}
}
