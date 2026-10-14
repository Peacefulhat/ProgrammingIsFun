#![allow(unused)]
#![allow(nonstandard_style)]

//generics: abstract stand-ins for concrete types or other properties.
//Generics allow us to replace specific types with a placeholder that represents multiple types to remove code duplication.
//We can express the behavior of generics or how they relate to other generics without
//knowing what will be in their place when compiling and running the code.

//We use generics to create definitions for items like function signatures or structs,
//which we can then use with many different concrete data types.

//You can use any identifier as a type parameter name.
//But we’ll use T because, by convention, type parameter names in Rust are short,
//often just one letter, and Rust’s type-naming convention is UpperCamelCase. Short for type, T

//When we use a parameter in the body of the function, we have to declare the parameter
//name in the signature so that the compiler knows what that name means.
//Similarly, when we use a type parameter name in a function signature, we have to declare
//the type parameter name before we use it. To define the generic largest function,
//we place type name declarations inside angle brackets, <>, between the name of the function and the parameter list

// Removing the duplication by extracting a function
fn Largest(List: &[i32]) -> &i32 {
    let mut LargestNumber = &List[0];

    for Item in List {
        if Item > LargestNumber {
            LargestNumber = Item;
        }
    }
    LargestNumber
}

// parameterized verion of Largest
fn PLargest<Type: std::cmp::PartialOrd>(List: &[Type]) -> &Type {
    // std::cmp::PartialOrd, with out this there will be an error.
    // because we don't implement the tarits for which for our `Type`.
    let mut LargestNumber = &List[0];

    for Item in List {
        if Item > LargestNumber {
            LargestNumber = Item;
        }
    }
    LargestNumber
}
//Note: Generic type parameters in a struct definition aren’t always the same as those you use in that same struct’s method signatures.

#[derive(Debug)]
struct point_2d<T> {
    X: T,
    Y: T,
}

/*
Note: that we have to declare T just after impl so that we can use T to specify that we’re implementing methods on the type Point<T>. By declaring T as a generic type after impl, Rust can identify that the type in the angle brackets in Point is a generic type rather than a concrete type. We could have chosen a different name for this generic parameter than the generic parameter declared in the struct definition, but using the same name is conventional. If you write a method within an impl that declares a generic type, that method will be defined on any instance of the type, no matter what concrete type ends up substituting for the generic type.
 */

impl<T: std::ops::Add<Output = T> + Clone> point_2d<T> {
    // hackish way to do things
    fn add(&self, P2: &point_2d<T>) -> Self {
        Self {
            X: (self.X.clone() + P2.X.clone()),
            Y: (self.Y.clone() + P2.Y.clone()),
        }
    }
}

/*
We can also specify constraints on generic types when defining methods on the type. We could, for example, implement methods only on Point<f32> instances rather than on Point<T> instances with any generic type. In Listing 10-10, we use the concrete type f32, meaning we don’t declare any types after impl.
 */
impl point_2d<f32> {
    fn addf(&self, P2: &point_2d<f32>) -> Self {
        Self {
            X: self.X + P2.X,
            Y: self.Y + P2.Y,
        }
    }
}

#[derive(Debug)]
struct point_3d<T1, T2, T3> {
    X: T1,
    Y: T2,
    Z: T3,
}

struct point_mix<T1, T2> {
    X: T1,
    Y: T2,
}

/*Generic type parameters in a struct definition aren’t always the same as those you use in that same struct’s method signatures. uses the generic types X1 and Y1 for the Point struct and X2 and Y2 for the mixup method signature to make the example clearer. The method creates a new Point instance with the x value from the self Point (of type X1) and the y value from the passed-in Point (of type Y2).
 */
impl<T1, T2> point_mix<T1, T2> {
    fn mixup<T3, T4>(self, other: point_mix<T3, T4>) -> point_mix<T1, T4> {
        point_mix {
            X: self.X,
            Y: other.Y,
        }
    }
}

/*The purpose of this example is to demonstrate a situation in which some generic parameters are declared with impl and some are declared with the method definition. Here, the generic parameters X1 and Y1 are declared after impl because they go with the struct definition. The generic parameters X2 and Y2 are declared after fn mixup because they’re only relevant to the method.
 */

#[derive(Debug)]
enum flag<T> {
    UNSET(T),
    SET(T),
}

fn main() {
    let number_list = vec![34, 50, 25, 100, 65];
    let result = Largest(&number_list);
    println!("The largest number is {result}");
    let number_list = vec![102, 34, 6000, 89, 54, 2, 43, 8];
    let number_list2 = vec!['a', 'b', 'c', 'd', 'z'];
    let result = PLargest::<char>(&number_list2);
    println!("Greatest Char:{}", result);
    /*
     test code
            let mut newVec = Vec::<i32>::new();
            newVec.push(2);
            newVec.push(4);
            newVec.push(8);
            newVec.push(16);
            newVec.push(32);
    w          println!("Vector:");
            for Item in &newVec {
                print!("{} ", Item);
            }
        */
    let result = Largest(&number_list);
    println!("The largest number is {result}");

    // generic struct
    let Player = point_2d::<f32> { X: 23.0, Y: 52.0 };
    let Player2 = point_2d::<i32> { X: 23, Y: 52 }; // explicitly defining the type .
    let Player3 = point_2d { X: 100, Y: 400 }; // auto type inferece from value
    println!(
        "Player: {:?}, Player2: {:?}, Player3: {:?}",
        Player, Player2, Player3
    );
    let Player4 = point_3d {
        X: 100,
        Y: 45.5,
        Z: String::from("PlayerPos"),
    };
    let Player5 = point_3d::<f32, i32, String> {
        X: 10.3,
        Y: 13,
        Z: String::from("PlayerPos"),
    };
    println!("Player4: {:?}, Player5: {:?}", Player4, Player5);

    // generic type in enums
    let mut State = flag::<bool>::SET(true);
    println!("State: {:?}", State);
    let mut State = flag::<i32>::UNSET(0);
    println!("State: {:?}", State);
    // most common example of generic enum are Result enum and Options enum form rust std

    let Player = point_2d::<f32> { X: 23.0, Y: 52.0 };
    let Player2 = point_2d::<f32> { X: 23.0, Y: 52.0 };
    //let Player2 = point_2d::<i32> { X: 23, Y: 24 }; error
    let Player3 = Player.addf(&Player2);
    println!(
        "layer: {:?} + Player2: {:?} = Player3: {:?}",
        Player, Player2, Player3
    );

    let p1 = point_mix { X: 5, Y: 10.4 };
    let p2 = point_mix { X: 'c', Y: "Hello" };
    let p3 = p1.mixup(p2);

    println!("p3.x = {}, p3.y = {}", p3.X, p3.Y);

    let integer = Some(5);
    let float = Some(5.0);
    /*
    When Rust compiles this code, it performs monomorphization. During that process, the compiler reads the values that have been used in Option<T> instances and identifies two kinds of Option<T>: One is i32 and the other is f64. As such, it expands the generic definition of Option<T> into two definitions specialized to i32 and f64, thereby replacing the generic definition with the specific ones.

    The monomorphized version of the code looks similar to the following (the compiler uses different names than what we’re using here for illustration):
    */
    enum Option_i32 {
        Some(i32),
        None,
    }

    enum Option_f64 {
        Some(f64),
        None,
    }

    let integer = Option_i32::Some(5);
    let float = Option_f64::Some(5.0);
    

    /*
        The generic Option<T> is replaced with the specific definitions created by the compiler. Because Rust compiles generic code into code that specifies the type in each instance, we pay no runtime cost for using generics. When the code runs, it performs just as it would if we had duplicated each definition by hand. The process of monomorphization makes Rust’s generics extremely efficient at runtime.

    */
}

/*
Note: Performance of Code Using Generics

You might be wondering whether there is a runtime cost when using generic type parameters. The good news is that using generic types won’t make your program run any slower than it would with concrete types.

Rust accomplishes this by performing monomorphization of the code using generics at compile time. Monomorphization is the process of turning generic code into specific code by filling in the concrete types that are used when compiled. In this process, the compiler does the opposite of the steps we used to create the generic function: The compiler looks at all the places where generic code is called and generates code for the concrete types the generic code is called with.

*/
