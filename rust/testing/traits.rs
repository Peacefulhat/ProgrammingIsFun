#![allow(nonstandard_style)]
#![allow(unused)]
use std::fmt::Display;
use std::fmt::Debug;
//A trait defines the functionality a particular type has and can share with other types.
//We can use traits to define shared behavior in an abstract way.
//We can use `trait bounds` to specify that a generic type can be any type that has certain behavior.

//Defining a Trait:

//A type’s behavior consists of the methods we can call on that type.
//Different types share the same behavior if we can call the same methods on all of those types.
//Trait definitions are a way to group method signatures together to define a set of behaviors necessary to accomplish some purpose.

trait summary {
    //    fn Summarize(&self) -> String;
    //Default implementations can call other methods in the same trait,
    //even if those other methods don’t have a default implementation.
    //In this way, a trait can provide a lot of useful functionality and only require implementors to specify a small part of it.
    fn SummarizeAuthor(&self) -> String;
    //Using Default Implementations
    fn Summarize(&self) -> String {
        format!("(Read more...) {}", self.SummarizeAuthor())
    }
}
//After the method signature, instead of providing an implementation within curly brackets, we use a semicolon.
//Each type implementing this trait must provide its own custom behavior for the body of the method.
//The compiler will enforce that any type that has the Summary trait will have the method summarize defined with this signature exactly.
//A trait can have multiple methods in its body: The method signatures are listed one per line, and each line ends in a semicolon.

#[derive(Debug)]
struct news_article {
    Headline: String,
    Location: String,
    Author: String,
    Content: String,
}

//Implementing a trait on a type is similar to implementing regular methods.
//The difference is that after impl, we put the trait name we want to implement, then use the for keyword,
//and then specify the name of the type we want to implement the trait for. Within the impl block,
//we put the method signatures that the trait definition has defined. Instead of adding a semicolon after each signature,
//we use curly brackets and fill in the method body with the specific behavior that we want the methods of the trait
//to have for the particular type.

impl summary for news_article {
    fn SummarizeAuthor(&self) -> String {
        format!("@{}", self.Author)
    }
    fn Summarize(&self) -> String {
        format!(
            "\n{}, by {} ({})\n\n {}\n",
            self.Headline, self.Author, self.Location, self.Content
        )
    }
}

#[derive(Debug)]
struct social_post {
    Username: String,
    Content: String,
    Reply: bool,
    Repost: bool,
}

/* commenting out for default implementation

impl summary for social_post {
    fn Summarize(&self) -> String {
        format!("{}: {}", self.Username, self.Content)
    }
}

 */

impl summary for social_post {
    fn SummarizeAuthor(&self) -> String {
        format!("@{}", self.Username)
    }
}
// use aggregator::{SocialPost, Summary};
// this is how we import the code form a module and the trait. we have to explecity import the trait

//Using Default Implementations
//Sometimes it’s useful to have default behavior for some or all of the methods in a trait instead of
//requiring implementations for all methods on every type. Then, as we implement the trait on a particular type,
//we can keep or override each method’s default behavior.


// using traits as parameter

fn Notify(Item: &impl summary) {
    //Instead of a concrete type for the item parameter, we specify the impl keyword and the trait name.
    //This parameter accepts any type that implements the specified trait. In the body of notify,
    //we can call any methods on item that come from the Summary trait
    
    println!("\nNotification: \nBreaking news! {}", Item.Summarize());
}

//multiple trait bounds exmaple
fn Notify2 <T: summary + Display> (Item: &T){
    
}

// clearer trait bound with where clause
//fn some_function<T: Display + Clone, U: Clone + Debug>(t: &T, u: &U) -> i32 {
fn some_function<T, U>(t: &T, u: &U)
where
    T: Display + Clone,
    U: Clone + Debug,
{
    
}


//Returning Types That Implement Traits
fn returns_summarizable() -> impl summary {
    // here returning a trait object, more on that later in chapter 18
    social_post {
        Username: String::from("horse_ebooks"),
        Content: String::from(
            "of course, as you probably already know, people",
        ),
        Reply: false,
        Repost: false,
    }
}

fn main() {
    let mut FirstNews = news_article {
        Headline: String::from("E3"),
        Location: String::from("Dubai, UAE"),
        Author: String::from("Peacefulhat"),
        Content: String::from(
            "Next Generation event on Games, Game Development and Gaming realeated techonology",
        ),
    };

    let mut FirstPost = social_post {
        Username: String::from("Peacefulhat"),
        Content: String::from("This Post is for new Game+ in Elden ring"),
        Reply: false,
        Repost: false,
    };
    println!("{:#?}", FirstNews);
    println!("{:#?}", FirstPost);
    let Summarize = FirstNews.Summarize();
    println!("{}", Summarize);
    let Summarize = FirstPost.Summarize();
    println!("{}", Summarize);

    Notify(&FirstNews);
    let ReturnedTrait = returns_summarizable();
    //println!("{:?}", ReturnedTrait);// error, traits object is not covered for now
}


//The impl Trait syntax works for straightforward cases but is actually syntax sugar for a longer form known as a trait bound;
/*
pub fn notify<T: Summary>(item: &T) {
    println!("Breaking news! {}", item.summarize());
}
// with multiple trait parameter parameter
pub fn notify(item1: &impl Summary, item2: &impl Summary)

Using impl Trait is appropriate if we want this function to allow item1 and item2 to have different types (as long as both types implement Summary). If we want to force both parameters to have the same type, however, we must use a trait bound, like this

pub fn notify<T: Summary>(item1: &T, item2: &T) {

multiple trait bounds:
We can also specify more than one trait bound. Say we wanted notify to use display formatting as well as summarize on item: We specify in the notify definition that item must implement both Display and Summary. We can do so using the + syntax:

pub fn notify(item: &(impl Summary + Display)) {

The + syntax is also valid with trait bounds on generic types:

pub fn notify<T: Summary + Display>(item: &T) {

With the two trait bounds specified, the body of notify can call summarize and use {} to format item.

*/
/*
Clearer Trait Bounds with where Clauses

Using too many trait bounds has its downsides. Each generic has its own trait bounds, so functions with multiple generic type parameters can contain lots of trait bound information between the function’s name and its parameter list, making the function signature hard to read. For this reason, Rust has alternate syntax for specifying trait bounds inside a where clause after the function signature. So, instead of writing this:

fn some_function<T: Display + Clone, U: Clone + Debug>(t: &T, u: &U) -> i32 {

we can use a where clause, like this:

fn some_function<T, U>(t: &T, u: &U) -> i32
where
    T: Display + Clone,
    U: Clone + Debug,
{

This function’s signature is less cluttered: The function name, parameter list, and return type are close together, similar to a function without lots of trait bounds.
*/

//Using Trait Bounds to Conditionally Implement Methods: (not get the point for now, if need go rust book this section)
//We can also conditionally implement a trait for any type that implements another trait. Implementations of a trait on any type that satisfies the trait bounds are called blanket implementations and are used extensively in the Rust standard library
