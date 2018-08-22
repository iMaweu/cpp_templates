#ifndef CHAPTER_2
#define CHAPTER_2

// CH2_1 Aim: To write a metafunction that takes a compound type and replace instances of a type x with type y
// It should be called as follows. replace_type<cmpd_type, x, y>:: type;
namespace CH2_1
{
  template <class c, class x, class y> struct replace_type;
  //template< class c, class x, class y> struct replace_type_impl;

  template< class c, class x, class y> 
  struct replace_type_impl
  {
    using type = c;
  };

  template <class c, class y>
  struct replace_type_impl <c, c, y>  // (int, int, long) replaces int with long
  {
    using type = y;
  };

  template<class c, class y>
  struct replace_type_impl <c*,c, y>  // (int*, int, long) replaces int * with long *
  {
    using type = y*;
  };

  template<class c, class y>
  struct replace_type_impl < c [], c, y>  // (int [], int [], long) replaces int [] with long []
  {
    using type = y [];
  };

  template <class c, class x, class y>
  struct replace_type
  {
    using type = typename replace_type_impl<c, x, y>::type ;
  };

  void run_tests ();
}

#endif  //CHAPTER_2