#![allow(nonstandard_style)]
#![allow(unused)]

pub mod garden;

fn main() {
    let Plant = garden::vegetables::vegetable {
        Name: String::from("Asparagus"),
        Calorie: 20,
        RichInVitamins: String::from("Vitamin K , Vitamin A, Vitamin C, folate"),
    };
    garden::VegitableDetails(&Plant);
    let temp = garden::sum::add(23, 24);
    println!("second module form one module: {}", temp);
}
