class Student{
    full_name:string;
    constructor(public first_name,public middle_name, public last_name){
        this.full_name = first_name+" "+middle_name+" "+last_name;
    }
}

interface Person{
    first_name: string;
    last_name: string;
}

function hello(person: Person){
    return "hello "+
    person.first_name+" "+
    person.last_name;
}

var user = new Student("DC", "Greate", "Lin");

document.body.innerHTML = hello(user);