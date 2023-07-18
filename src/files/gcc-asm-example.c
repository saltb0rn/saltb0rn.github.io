#include <stdio.h>

// global extern variables
int vg_int = 1;
long vg_long = 2;

// global static variables
static float v_float = 3.1;
static double v_double = 4.1;

// uninitialized extern variables
char c_char;

// uninitialized stataic variables
static char c2_char;

// struct
struct person {
  char *name;
  int age;
  int height;
};

// function
int add_num(int num)
{
  return vg_int + num;
}

int main()
{
  // local variables
  int res = 0;
  int growth_to = 19;

  // local static variables
  static int slocal = 0;
  
  // person initialization
  struct person p_inst = {
    .name="Jack",
    .height=160
  };
  p_inst.age = 14;

  // pointer
  struct person *ptr = &p_inst;
  int *ptr_int = &growth_to;

  // dereference pointer and call function 
  p_inst.age = add_num(*ptr_int);

  // call external functions
  printf("name: %s, age: %d, height: %d", ptr->name, ptr->age, ptr->height);
  // equivalent to
  // printf("name: %s, age: %d, height: %d", (*ptr).name, (*ptr).age, (*ptr).height);

  return res;
  
}
