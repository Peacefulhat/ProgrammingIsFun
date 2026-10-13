#![allow(unused)]
#![allow(nonstandard_style)]

//generics: abstract stand-ins for concrete types or other properties.
//Generics allow us to replace specific types with a placeholder that represents multiple types to remove code duplication.
//We can express the behavior of generics or how they relate to other generics without
//knowing what will be in their place when compiling and running the code.

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

fn main() {
    let number_list = vec![34, 50, 25, 100, 65];

    let result = Largest(&number_list);
    println!("The largest number is {result}");

    let number_list = vec![102, 34, 6000, 89, 54, 2, 43, 8];
    /*
 test code
        let mut newVec = Vec::<i32>::new();
        newVec.push(2);
        newVec.push(4);
        newVec.push(8);
        newVec.push(16);
        newVec.push(32);
          println!("Vector:");
        for Item in &newVec {
            print!("{} ", Item);
        }
    */
    let result = Largest(&number_list);
    println!("The largest number is {result}");
}
