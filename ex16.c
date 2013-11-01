#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person {
  char *name;
  int age;
  int height;
  int weight;
};


struct Person *Person_create(char *name, int age, int height, int weight)
{
  struct Person *who = malloc(sizeof(struct Person));
  assert(who != NULL);

  who->name = strdup(name);
  who->age = age;
  who->height = height;
  who->weight = weight;

  return who;
}

void Person_destroy(struct Person *who)
{
  assert(who != NULL);

  free(who->name);
  free(who);
}

void Person_print(struct Person *who)
{
  printf("Name: %s\n", who->name);
  printf("\tAge: %d\n", who->age);
  printf("\tHeight: %d\n", who->height);
  printf("\tWeight: %d\n", who->weight);
}

void Person_print_extra_credit(struct Person who)
{
  //To show that it copies the struct on call
  who.weight = 10;
  printf("Name: %s\n", who.name);
  printf("\tAge: %d\n", who.age);
  printf("\tHeight: %d\n", who.height);
  printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[])
{
  struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
  struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

  printf("Joe is at memory location %p:\n", joe);
  Person_print(joe);

  printf("Frank is at memory location %p:\n", frank);
  Person_print(frank);

  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;
  Person_print(joe);

  frank->age += 20;
  frank->weight += 20;
  Person_print(frank);

  Person_destroy(joe);
  Person_destroy(frank);


  //Extra Credit
  printf("\n----EXTRA CREDIT----\n");
  struct Person j2;
  j2.name = "j2";
  j2.height = 197;
  j2.age = 20;
  j2.weight = 97;

  Person_print_extra_credit(j2);
  Person_print(&j2);

  return 0;
}
