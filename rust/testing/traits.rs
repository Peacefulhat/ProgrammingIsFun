#![allow(nonstandard_style)]
#![allow(unused)]

//A trait defines the functionality a particular type has and can share with other types.
//We can use traits to define shared behavior in an abstract way.
//We can use `trait bounds` to specify that a generic type can be any type that has certain behavior.

//Defining a Trait:

//A type’s behavior consists of the methods we can call on that type.
//Different types share the same behavior if we can call the same methods on all of those types.
//Trait definitions are a way to group method signatures together to define a set of behaviors necessary to accomplish some purpose.

trait summary {
    //    fn Summarize(&self) -> String;

    //Using Default Implementations
    fn Summarize(&self) -> String {
        String::from("(Read more...)")
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
impl summary for social_post {}
// use aggregator::{SocialPost, Summary};
// this is how we import the code form a module and the trait. we have to explecity import the trait

//Using Default Implementations
//Sometimes it’s useful to have default behavior for some or all of the methods in a trait instead of
//requiring implementations for all methods on every type. Then, as we implement the trait on a particular type,
//we can keep or override each method’s default behavior.

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
}
