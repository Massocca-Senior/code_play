use std::thread;
use std::time::Duration;
use std::sync::mpsc;

mod second;
use second::ClassName;

fn another_funtion() {
    println!("Hello, man!")
}

fn do_while() {
    let mut number = 1;
    while number < 4 {
        println!("{}", number);
        number += 1;
    }
    println!("EXIT!");
}

fn do_for(){
    let a = [10 ,20, 30, 40, 50];
    for i in a.iter() {
        println!("值为 : {}", i);
    }
}

fn do_loop(){
    let s = ['R', 'U', 'N', 'O', 'O', 'B'];
    let mut i = 0;
    let location = loop {
        let ch = s[i];
        if ch == 'O' {
            break i;
        }
        println!("\'{}\'", ch);
        i += 1;
    };

    println!("\'O\' index is {}", location);

}

fn do_ref_val() {
    let mut s1 = String::from("Hello");
    let s2 = &mut s1;
    //let s3 = s1;
    s2.push_str("abcdef");
    s2.pop();
    s2.pop();

    println!("{}", s2);
}

/*
fn do_dangling() -> &String {
    let s = String::from("aaaaa");
    &s
}

*/

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn aera(&self) -> u32 {
        self.width * self.height
    }
}

impl Rectangle {
    fn create(width: u32, height: u32) -> Rectangle {
        Rectangle {width, height}
    }
}

fn do_struct_func() {
    let rect1 = Rectangle {width: 30, height: 50};
    println!("rect1 is {} {}", rect1.width, rect1.height);
    println!("rect1 is {:?} {}", rect1, rect1.aera());
    println!("rect1 is {:#?}", rect1);
    let rect2 = Rectangle::create(40, 50);
    println!("rect2 is {:?} {}", rect2, rect2.aera());
    println!("rect3 is {:#?}", rect2);

}

#[derive(Debug)]
enum Book {
    Papery{index: u32},
    Electronic{url: String},
}

fn do_enum_func() {
    let book = Book::Papery{ index: 1001 };
    let ebook = Book::Electronic{url: String::from("url...")};

    println!("{:?}", book);

    match ebook {
        Book::Papery{ index } => {
            println!("{}", index);
        },
        Book::Electronic { url } => {
            println!("{}", url);
        }
    }
}

trait Descriptive {
    fn describe(&self) -> String {
        String::from("[Object]")
    }
}

struct Person {
    name: String,
    age: u8
}
/*
fn output(object: impl Descriptive) {
    println!("{}", object.describe());
}
*/

fn output<T: Descriptive> (object: T) {
    println!("{}", object.describe());
}

fn do_trait(){

    impl Descriptive for Person {
        fn describe(&self) -> String {
            format!("{} {}", self.name, self.age)
        }
    }

    let cali = Person {
        name: String::from("cali"),
        age: 24
    };

    println!("{}", cali.describe());

    output(cali);
}

fn longer<'a>(s1: &'a str, s2: &'a str) -> &'a str {
    if s2.len() > s1.len() {
        s2
    } else {
        s1
    }
}

/*
fn longer(s1: &str, s2: &str) -> &str {
    if s2.len() > s1.len() {
        s2
    } else {
        s1
    }
}
*/

fn live_cycle() {
    let r;
    {
        let s1 = "rust";
        let s2 = "ecmacscript";
        r = longer(s1, s2);
    }
    println!("{} is longer", r);
}

use std::io::prelude::*;
use std::fs;
use std::fs::File;
use std::fs::OpenOptions;


fn do_file_operation() {
    let mut str_buf = String::new();
    std::io::stdin().read_line(&mut str_buf).expect("Failed to read line");

    println!("Your input line is \n {}", str_buf);

    let ret = fs::File::create("/tmp/aaa.txt");

    let text = std::fs::read_to_string("/tmp/aaa.txt").unwrap();

    println!("{}", text);

    let text1 = std::fs::read("/tmp/aaa.txt").unwrap();

    println!("{:?}", text1);

    let mut buffer  = [0u8; 5];
    let mut file = fs::File::open("/tmp/aaa.txt").unwrap();

    file.read(&mut buffer).unwrap();
    println!("{:?}", buffer);
    file.read(&mut buffer).unwrap();
    println!("{:?}", buffer);

    let mut file1 = File::create("/tmp/aaa1.txt").unwrap();
    file1.write(b"FROM RUST PROGRAM ").unwrap();

    let mut file2 = OpenOptions::new().append(true).open("/tmp/aaa1.txt").unwrap();

    file2.write(b"APPEND WORD").unwrap();
}

use std::collections::HashMap;

fn do_character_and_collections()
{
    let mut vector = vec![1, 2, 4, 8, 9];

    vector.push(12);
    vector.push(14);
    println!("{:?}", vector);

    let mut v1: Vec<i32> = vec![1, 2, 3, 4];
    let mut v2: Vec<i32> = vec![5, 6, 7, 8];

    v1.append(&mut v2);
    println!("{:?}",v1);

    let v3 = vec![1, 2, 3, 4];

    println!("{}", match v3.get(0) {
        Some(v) => v.to_string(),
        None => "None".to_string()
    });

    for i in &v3 {
        println!("{}", i);
    }

    let mut map = HashMap::new();

    map.insert("color", "red");
    map.insert("size", "10 m^2");

    println!("{}", map.get("color").unwrap());

    for p in map.iter() {
        println!("{:?}",p );
    }

}

fn do_class_func() {
    let object = ClassName::new(1024);
    object.public_method();
}

fn spawn_function() {
    for i in 0..5 {
        println!("spawned therad print {}", i);
        thread::sleep(Duration::from_millis(1));
    }
}

fn do_mutil_thread() {

    let handle = thread::spawn(spawn_function);

    for i in 0..3 {
        println!("main therad print {}", i);
        thread::sleep(Duration::from_millis(1));
    }
    handle.join().unwrap();

    let s = "Hello man";

    let handle1 = std::thread::spawn(move || {
       println!("{}", s); 
    });
    handle1.join().unwrap();

    let (tx, rx) = mpsc::channel();

    std::thread::spawn(move || {
        let val = String::from("Hi man");
        tx.send(val).unwrap();
    });
    println!("{}", rx.recv().unwrap());
}

fn main() {
    println!("Hello, world!");
    another_funtion();
    do_while();
    do_for();
    do_loop();
    do_ref_val();
    do_struct_func();
    do_enum_func();
    do_trait();
    live_cycle();
    let args = std::env::args();
    println!("{:?}",args);
    do_file_operation();
    do_character_and_collections();
    do_class_func();
    do_mutil_thread();
}
