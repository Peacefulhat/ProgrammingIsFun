/*
Tests are Rust functions that verify that the non-test code is functioning in the expected manner. The bodies of test functions typically perform these three actions:

    Set up any needed data or state.
    Run the code you want to test.
    Assert that the results are what you expect.
 */
/*At its simplest, a test in Rust is a function that’s annotated with the test attribute. Attributes are metadata about pieces of Rust code; one example is the derive attribute we used with structs in Chapter 5. To change a function into a test function, add #[test] on the line before fn.*/

fn add_two(n: i32) -> i32 {
    n + 2
}

#[test]
fn test_runner() {
    let args = 23;
    assert_eq!(add_two(args), 25); // takes to values, and check if they are equal.
    assert_ne!(add_two(args), 23); //takes to values, and check if they are not equal.
}
#[test]
fn test_runner2() {
    //    panic!("Make this test fail");
}

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width < other.width && self.height > other.height
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    //by adding the attribute should_panic to our test function.
    //The test passes if the code inside the function panics; the test fails if the code inside the function doesn’t panic
    #[should_panic(expected = "Fail unable to fit")]
    fn larger_can_hold_smaller() {
        let larger = Rectangle {
            width: 8,
            height: 7,
        };
        let smaller = Rectangle {
            width: 5,
            height: 1,
        };
        //Adding Custom Failure Messages:
        assert!(larger.can_hold(&smaller), "Fail unable to fit");
    }

    #[test]
    fn smaller_cannot_hold_larger() {
        let larger = Rectangle {
            width: 8,
            height: 7,
        };
        let smaller = Rectangle {
            width: 5,
            height: 1,
        };

        assert!(!smaller.can_hold(&larger)); // assert take a boolean value,
    }
    
    // writing test with Result struct.
    #[test]
    fn test_runner3() -> Result<(), String> {
        let result = add_two(2);

        if result == 4 {
            Ok(())
        } else {
            Err(String::from("two plus two does not equal four"))
        }
    }
}

fn main() {
    return ();
}

/*
Under the surface, the assert_eq! and assert_ne! macros use the operators == and !=, respectively. When the assertions fail, these macros print their arguments using debug formatting, which means the values being compared must implement the PartialEq and Debug traits. All primitive types and most of the standard library types implement these traits. For structs and enums that you define yourself, you’ll need to implement PartialEq to assert equality of those types. You’ll also need to implement Debug to print the values when the assertion fails. Because both traits are derivable traits, as mentioned in Listing 5-12 in Chapter 5, this is usually as straightforward as adding the #[derive(PartialEq, Debug)] annotation to your struct or enum definition. See Appendix C, “Derivable Traits,” for more details about these and other derivable traits.
*/
