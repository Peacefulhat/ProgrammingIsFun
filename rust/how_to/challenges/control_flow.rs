#![allow(nonstandard_style)]

fn main() {
    // C = ((F-32)*5)/9 Fahrenheit to Celsius
    // (9C/5) + 32 = F
    const TEMP_F: f32 = 80.0;
    const TEMP_C: f32 = ((TEMP_F - 32.0) * 5.0) / 9.0;
    println!("F to C: {:.3} C", ((TEMP_F - 32.0) * 5.0) / 9.0);
    println!("C to F: {:.3} F\n", ((9.0 * TEMP_C) / 5.0) + 32.0);
    // nth fibonnaci number

    const Nth: i32 = 7;
    // 0 1 1 2 3 5 8 13
    let mut A = 0;
    let mut B = 1;
    for _ in 1..Nth - 2 {
        let C = A + B;
        A = B;
        B = C;
    }
    println!("nth fibonnaci number: {}\n", A + B);

    // Half lyric of christmas carol
    println!("Half lyric of christmas carol: ");
    let mut Rep = 3;
    println!("Oh, come, all ye faithful,");
    println!("Joyful and triumphant!");
    println!("Oh, come ye, oh, come ye to Bethlehem;");
    println!("Come and behold him");
    println!("Born the king of angels:");
    while Rep != 0 {
        println!("Oh, come, let us adore him,");
        Rep -= 1;
    }
}
