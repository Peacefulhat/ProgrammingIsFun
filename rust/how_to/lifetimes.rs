#![allow(unused)]
#![allow(nonstandard_style)]
//Lifetimes are another kind of generic that we’ve already been using. Rather than ensuring that a type has the behavior we want,
//lifetimes ensure that references are valid as long as we need them to be.
/*
The Rust compiler has a borrow checker that compares scopes to determine whether all borrows are valid. Listing 10-17 shows the same code as Listing 10-16 but with annotations showing the lifetimes of the variables.

 [This code does not compile!]
fn main() {
    let r;                // ---------+-- 'a
                          //          |
    {                     //          |
        let x = 5;        // -+-- 'b  |
        r = &x;           //  |       |
    }                     // -+       |
                          //          |
    println!("r: {r}");   //          |
}                         // ---------+

Listing 10-17: Annotations of the lifetimes of r and x, named 'a and 'b, respectively

Here, we’ve annotated the lifetime of r with 'a and the lifetime of x with 'b. As you can see, the inner 'b block is much smaller than the outer 'a lifetime block. At compile time, Rust compares the size of the two lifetimes and sees that r has a lifetime of 'a but that it refers to memory with a lifetime of 'b. The program is rejected because 'b is shorter than 'a: The subject of the reference doesn’t live as long as the reference.

Listing 10-18 fixes the code so that it doesn’t have a dangling reference and it compiles without any errors.

fn main() {
    let x = 5;            // ----------+-- 'b
                          //           |
    let r = &x;           // --+-- 'a  |
                          //   |       |
    println!("r: {r}");   //   |       |
                          // --+       |
}                         // ----------
 */

fn lifetime1() {
    let mut r: &i32;
    {
        let x: i32 = 5;
        r = &x;
    }
    //println!("{}", r); //error because x will be droped after the scope ends
    // lifetime of the x is only inside the block that x is defined in.
}

/*fn lifetime2() {
    let mut r: &i32;
    let x: i32 = 5;
    r = &x;

    println!("{}", r); //error because x will be droped after the scope ends
                       // lifetime of the x is only inside the block that x is defined in.
}
 */

/*
fn longest(x: &str, y: &str) -> &str {
    if x.len() > y.len() { x } else { y }
}
When we’re defining this function, we don’t know the concrete values that will be passed into this function, so we don’t know whether the if case or the else case will execute. We also don’t know the concrete lifetimes of the references that will be passed in, so we can’t look at the scopes as we did in Listings 10-17 and 10-18 to determine whether the reference we return will always be valid. The borrow checker can’t determine this either, because it doesn’t know how the lifetimes of x and y relate to the lifetime of the return value. To fix this error, we’ll add generic lifetime parameters that define the relationship between the references so that the borrow checker can perform its analysis.
 */

fn string_literal() -> &'static str {
    "string_literal: Hello, World"
}

use std::fmt::Display;

fn longest_with_an_announcement<'a, T>(x: &'a str, y: &'a str, ann: T) -> &'a str
where
    T: Display,
{
    println!("Announcement! {ann}");
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

//This is the longest function from Listing 10-21 that returns the longer of two string slices. But now it has an extra parameter named ann of the generic type T, which can be filled in by any type that implements the Display trait as specified by the where clause. This extra parameter will be printed using {}, which is why the Display trait bound is necessary. Because lifetimes are a type of generic, the declarations of the lifetime parameter 'a and the generic type parameter T go in the same list inside the angle brackets after the function name.

fn main() {
    //lifetime anotation syntax
    /*Lifetime annotations don’t change how long any of the references live. Rather, they describe the relationships of the lifetimes of multiple references to each other without affecting the lifetimes. Just as functions can accept any type when the signature specifies a generic type parameter, functions can accept references with any lifetime by specifying a generic lifetime parameter.*/

    /*Lifetime annotations have a slightly unusual syntax: The names of lifetime parameters must start with an apostrophe (') and are usually all lowercase and very short, like generic types. Most people use the name 'a for the first lifetime annotation. We place lifetime parameter annotations after the & of a reference, using a space to separate the annotation from the reference’s type.*/

    //&i32        // a reference
    //&'a i32     // a reference with an explicit lifetime
    //&'a mut i32 // a mutable reference with an explicit lifetime
    let mut x = 23;
    let y = &mut x;
    *y = 33;
    println!("{}", x);
    let Astr = String::from("Heloo");
    let Bstr = String::from("Bcd");
    let Result = longest(&Astr, &Bstr);
    println!("{}", Result);
    let string1 = String::from("long string is long");

    {
        let string2 = String::from("xyz");
        let result = longest(string1.as_str(), string2.as_str());
        println!("The longest string is {result}");
    }
    /*
    let string1 = String::from("long string is long");
    let result;
    {
        let string2 = String::from("xyz");
        result = longest(string1.as_str(), string2.as_str());
    }
    println!("The longest string is {result}");
     */

    //    In Struct Definitions

    /*
    So far, the structs we’ve defined all hold owned types. We can define structs to hold references, but in that case, we would need to add a lifetime annotation on every reference in the struct’s definition. Listing 10-24 has a struct named ImportantExcerpt that holds a string slice.

         */
    let string2 = String::from("xyz");
    #[derive(Debug)]
    struct Chunk<'a> {
        part: &'a str,
    }
    let novel = String::from("Call me Ishmael. Some years ago...");
    let first_sentence = novel.split('.').next().unwrap();
    println!("{}", first_sentence);
    let i = Chunk {
        part: first_sentence,
    }; // here Chunk can not outlive the novel
    println!("{:?}", i);

    let s: &'static str = "I have a static lifetime.";
    println!("{}", s);
    println!("{}", string_literal());
    println!(
        "{}",
        longest_with_an_announcement(string1.as_str(), string2.as_str(), 2)
    );
}

/*
To use lifetime annotations in function signatures, we need to declare the generic lifetime parameters inside angle brackets between the function name and the parameter list, just as we did with generic type parameters.

We want the signature to express the following constraint: The returned reference will be valid as long as both of the parameters are valid. This is the relationship between lifetimes of the parameters and the return value. We’ll name the lifetime 'a and then add it to each reference
 */

fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() {
        x
    } else {
        y
    }
}

/*The function signature now tells Rust that for some lifetime 'a, the function takes two parameters, both of which are string slices that l ive at least as long as lifetime 'a. The function signature also tells Rust that the string slice returned from the function will live at least as long as lifetime 'a. In practice, it means that the lifetime of the reference returned by the longest function is the same as the smaller of the lifetimes of the values referred to by the function arguments. These relationships are what we want Rust to use when analyzing this code.

Remember, when we specify the lifetime parameters in this function signature, we’re not changing the lifetimes of any values passed in or returned. Rather, we’re specifying that the borrow checker should reject any values that don’t adhere to these constraints. Note that the longest function doesn’t need to know exactly how long x and y will live, only that some scope can be substituted for 'a that will satisfy this signature.

When annotating lifetimes in functions, the annotations go in the function signature, not in the function body. The lifetime annotations become part of the contract of the function, much like the types in the signature. Having function signatures contain the lifetime contract means the analysis the Rust compiler does can be simpler. If there’s a problem with the way a function is annotated or the way it is called, the compiler errors can point to the part of our code and the constraints more precisely. If, instead, the Rust compiler made more inferences about what we intended the relationships of the lifetimes to be, the compiler might only be able to point to a use of our code many steps away from the cause of the problem.

When we pass concrete references to longest, the concrete lifetime that is substituted for 'a is the part of the scope of x that overlaps with the scope of y. In other words, the generic lifetime 'a will get the concrete lifetime that is equal to the smaller of the lifetimes of x and y. Because we’ve annotated the returned reference with the same lifetime parameter 'a, the returned reference will also be valid for the length of the smaller of the lifetimes of x and y.*/

// lifetime elision:

// fn first_word(s: &str) -> &str (new thing backed into the compiler )
// fn fist_word <'a> (s: & 'a str) -> & 'a str ( old and still vaild way of doing thing)

//This piece of Rust history is relevant because it’s possible that more deterministic patterns will emerge and be added to the compiler. In the future, even fewer lifetime annotations might be required.

//The patterns programmed into Rust’s analysis of references are called the lifetime elision rules. These aren’t rules for programmers to follow; they’re a set of particular cases that the compiler will consider, and if your code fits these cases, you don’t need to write the lifetimes explicitly.

//Lifetimes on function or method parameters are called input lifetimes, and lifetimes on return values are called output lifetimes.

//The compiler uses three rules to figure out the lifetimes of the references when there aren’t explicit annotations. The first rule applies to input lifetimes, and the second and third rules apply to output lifetimes. If the compiler gets to the end of the three rules and there are still references for which it can’t figure out lifetimes, the compiler will stop with an error. These rules apply to fn definitions as well as impl blocks.

//The first rule is that the compiler assigns a lifetime parameter to each parameter that’s a reference. In other words, a function with one parameter gets one lifetime parameter: fn foo<'a>(x: &'a i32); a function with two parameters gets two separate lifetime parameters: fn foo<'a, 'b>(x: &'a i32, y: &'b i32); and so on.

//The second rule is that, if there is exactly one input lifetime parameter, that lifetime is assigned to all output lifetime parameters: fn foo<'a>(x: &'a i32) -> &'a i32.

//The third rule is that, if there are multiple input lifetime parameters, but one of them is &self or &mut self because this is a method, the lifetime of self is assigned to all output lifetime parameters. This third rule makes methods much nicer to read and write because fewer symbols are necessary.

/*
Let’s pretend we’re the compiler. We’ll apply these rules to figure out the lifetimes of the references in the signature of the first_word function in Listing 10-25. The signature starts without any lifetimes associated with the references:

fn first_word(s: &str) -> &str {

Then, the compiler applies the first rule, which specifies that each parameter gets its own lifetime. We’ll call it 'a as usual, so now the signature is this:

fn first_word<'a>(s: &'a str) -> &str {

The second rule applies because there is exactly one input lifetime. The second rule specifies that the lifetime of the one input parameter gets assigned to the output lifetime, so the signature is now this:

fn first_word<'a>(s: &'a str) -> &'a str {

Now all the references in this function signature have lifetimes, and the compiler can continue its analysis without needing the programmer to annotate the lifetimes in this function signature.

Let’s look at another example, this time using the longest function that had no lifetime parameters when we started working with it in Listing 10-20:

fn longest(x: &str, y: &str) -> &str {

Let’s apply the first rule: Each parameter gets its own lifetime. This time we have two parameters instead of one, so we have two lifetimes:

fn longest<'a, 'b>(x: &'a str, y: &'b str) -> &str {

You can see that the second rule doesn’t apply, because there is more than one input lifetime. The third rule doesn’t apply either, because longest is a function rather than a method, so none of the parameters are self. After working through all three rules, we still haven’t figured out what the return type’s lifetime is. This is why we got an error trying to compile the code in Listing 10-20: The compiler worked through the lifetime elision rules but still couldn’t figure out all the lifetimes of the references in the signature.

Because the third rule really only applies in method signatures, we’ll look at lifetimes in that context next to see why the third rule means we don’t have to annotate lifetimes in method signatures very often.

*/

/*In Method Definitions

When we implement methods on a struct with lifetimes, we use the same syntax as that of generic type parameters, as shown in Listing 10-11. Where we declare and use the lifetime parameters depends on whether they’re related to the struct fields or the method parameters and return values.

Lifetime names for struct fields always need to be declared after the impl keyword and then used after the struct’s name because those lifetimes are part of the struct’s type.

In method signatures inside the impl block, references might be tied to the lifetime of references in the struct’s fields, or they might be independent. In addition, the lifetime elision rules often make it so that lifetime annotations aren’t necessary in method signatures. Let’s look at some examples using the struct named ImportantExcerpt that we defined in Listing 10-24.

First, we’ll use a method named level whose only parameter is a reference to self and whose return value is an i32, which is not a reference to anything:
 */

/*impl<'a> ImportantExcerpt<'a> {
    fn level(&self) -> i32 {
        3
    }
}
*/
//The lifetime parameter declaration after impl and its use after the type name are required, but because of the first elision rule, we’re not required to annotate the lifetime of the reference to self.

//Here is an example where the third lifetime elision rule applies:

/*
impl<'a> ImportantExcerpt<'a> {
    fn announce_and_return_part(&self, announcement: &str) -> &str {
        println!("Attention please: {announcement}");
        self.part
    }
}
*/
//There are two input lifetimes, so Rust applies the first lifetime elision rule and gives both &self and announcement their own lifetimes. Then, because one of the parameters is &self, the return type gets the lifetime of &self, and all lifetimes have been accounted for.

//The Static Lifetime

//One special lifetime we need to discuss is 'static, which denotes that the affected reference can live for the entire duration of the program. All string literals have the 'static lifetime, which we can annotate as follows:

//let s: &'static str = "I have a static lifetime.";

//The text of this string is stored directly in the program’s binary, which is always available. Therefore, the lifetime of all string literals is 'static.

//You might see suggestions in error messages to use the 'static lifetime. But before specifying 'static as the lifetime for a reference, think about whether or not the reference you have actually lives the entire lifetime of your program, and whether you want it to. Most of the time, an error message suggesting the 'static lifetime results from attempting to create a dangling reference or a mismatch of the available lifetimes. In such cases, the solution is to fix those problems, not to specify the 'static lifetime.
