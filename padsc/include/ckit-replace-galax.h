// ckit-replace-galax:  replaces galax.h and limits.h
//
// ckit reads this file instead of the usual galax.h and limits.h includes.
// See the top of pglx-internal.h file for the set of include files that
// get skipped over.
//
// The goal is to provide a minimum set of declarations which mimic
// those found in galax and limits includes -- just enough to allow ckit
// to type pads include files and code generated by the padsc compiler with the -x flag.
//
// There are two advantages to this approach.
//   1. ckit does not have to parse complex system includes which
//        often use special-case compiler tricks that can confuse
//        it.  We used to fix problems related to gcc tricks
//        by undefining __GNUC__, but this only solved most of the
//        problem cases.  The ckit-replace approach is much simpler,
//        as we do not even attempt to parse actual system files.
//        It should be more portable than our previous approach.
//   2. ckit parses less stuff, so the padsc compiler will be faster.
//
// The main disadvantage of this approach is that if you use a new
// glax type or function in a pads header file, or in generated
// code, you need to add a declaration here.  Note that in the case
// of codegen using a function that is not declared here, if you
// use the pcgen-macros approach and declare a codegen macro that
// hides the use of the function, you do not need to declare the
// function here.
//
// Details:
//
// See ckit-replace.h for more details.
// 
// 

#ifndef __CKIT_REPLACE_GALAX_H__
#define __CKIT_REPLACE_GALAX_H__
typedef void *item;

#endif  /*  __CKIT_REPLACE_GALAX_H__  */
