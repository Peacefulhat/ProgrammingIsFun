
pub mod vegetables;
pub fn VegitableDetails(Vegetable: &vegetables::vegetable) {
    println!("Vegetable:");
    println!("Name: {}", Vegetable.Name);
    println!("Calorie: {} cal", Vegetable.Calorie);
    println!("RichInVitamins: {}", Vegetable.RichInVitamins);
}

pub mod sum{
    pub fn add(A:u8, B:u8) -> u16{
        (A + B).into()
    }
}
