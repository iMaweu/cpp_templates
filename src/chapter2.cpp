#include <cassert>
#include <type_traits>
#include "chapter2.h"


namespace CH2_1
{
  void run_tests ()
  {
    static_assert(std::is_same <replace_type <int, int, long>::type, long>::value );
    static_assert(std::is_same <replace_type <int*, int, long>::type, long*>::value );
    static_assert(std::is_same <replace_type <int[], int, long>::type, long[]>::value );

    static_assert(std::is_same <replace_type <int, char, long>::type, int>::value );
    static_assert(std::is_same <replace_type <int*, char, long>::type, int*>::value );
    static_assert(std::is_same <replace_type <int[], int[], long[]>::type, long[]>::value );

    static_assert(std::is_same<replace_type<int[],int,long>::type,long[]>::value );
    static_assert(std::is_same<replace_type<int*[],int*,long>::type,long[]>::value );
    //static_assert(std::is_same<replace_type<int[],int[],long[]>::type,long[][]>::value );
    static_assert(std::is_same<replace_type<int [],int,long*>::type,long* []>::value );
    static_assert(std::is_same<replace_type<int [],char,long>::type,int []>::value );
    static_assert(std::is_same<replace_type<int* [],char,long>::type,int* []>::value );
    return;
  }
}
