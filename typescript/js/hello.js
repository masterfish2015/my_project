var Student = (function () {
    function Student(first_name, middle_name, last_name) {
        this.first_name = first_name;
        this.middle_name = middle_name;
        this.last_name = last_name;
        this.full_name = first_name + " " + middle_name + " " + last_name;
    }
    return Student;
}());
function hello(person) {
    return "hello " +
        person.first_name + " " +
        person.last_name;
}
var user = new Student("DC", "Greate", "Lin");
document.body.innerHTML = hello(user);
