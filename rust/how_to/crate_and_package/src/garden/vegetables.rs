#[derive(Debug)]

// we have to make the struct and its members public to make them public
pub struct vegetable {
    pub Name: String,
    pub Calorie: u32,
    pub RichInVitamins: String,
}

// making whole enum public if we add pub at front of enum
pub enum Appetizer {
    Soup,
    Salad,
}
