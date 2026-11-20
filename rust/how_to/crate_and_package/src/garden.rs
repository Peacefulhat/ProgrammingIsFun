
pub mod vegetables;
pub fn VegitableDetails(Vegetable: &vegetables::vegetable) {
    println!("Vegetable:");
    println!("Name: {}", Vegetable.Name);
    println!("Calorie: {} cal", Vegetable.Calorie);
    println!("RichInVitamins: {}", Vegetable.RichInVitamins);
}

fn plog(Str: &str) {
    println!("{}", Str);
}
//We can construct relative paths that begin in the parent module, rather than the
//current module or the crate root, by using super at the start of the path. This is
//like starting a filesystem path with the .. syntax that means to go to the parent directory.
//Using super allows us to reference an item that we know is in the parent module,
//which can make rearranging the module tree easier when the module is closely related to the parent
//but the parent might be moved elsewhere in the module tree someday.

pub mod sum{
    pub fn add(A:u8, B:u8) -> u16{
        (A + B).into()
    }
    // upper module/parent module function, structs, enums etc. is now visibale in the `super` keyword.

    pub fn log(Str: &str){
        super::plog(&Str);
    }
}
