pub struct ClassName {
    filed: i32,
}

impl ClassName {
    pub fn new(value: i32) -> ClassName {
        ClassName {
            filed: value
        }
    }

    pub fn public_method(&self){
        println!("from public method");
        self.private_method();
    }
    fn private_method(&self) {
        println!("from private method, filed {}", self.filed);
    }
}