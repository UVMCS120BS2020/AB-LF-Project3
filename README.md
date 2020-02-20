# Project 3
Due on Gradescope by Friday, February 21st.
For this project you will design, implement, test, and use C++ class inheritance with components.

## Requirements
- You may work individually or with a partner of your choosing.
    - You may reuse code from previous project(s), if appropriate.
    
- [x] All of your programming files should be in a private GitHub repository in your section’s organization.
    - [x]  The repository must be named with your initials + dash + Project3 (e.g. LD-JH-Project3).
    - [x]  The repository should have a `.gitignore` file and a README file.
    
- [x]  You will need to have at least four classes, each of which satisfy exactly one of these requirements:
    - [x]  A parent class that may or may not be abstract;
    - [x]  A child class that inherits from the parent class;
    - [x]  An unrelated class (that does not inherit from the parent or child classes); and
    - [x]  A component class, an object of which can be included as a field in any of the other three classes.
    
Think about what each of the classes will represent:

- What added or modified methods will the child class have? 

> 

- What added fields will the child class have? 

>

- Where does the component belong? 

>

- How will the unrelated class interact with the others?

>

- [x]  Your classes should be declared in header file(s) (with comments) and defined in corresponding `.cpp` file(s).

- [x]  To make sure your classes are working the way you designed, include a `testing.cpp` file that has a main function 
and tests all of your non-trivial methods thoroughly.
    - [ ]  Put an `add_executable` line in `CMakeLists.txt` to create an executable for your testing program.
    
- [x]  Use your classes to have a fully-functioning program in` main.cpp`. The program should be interactive.
The more effort you put in, the more you will impress the graders and get a good grade.
    - [x]  Put an `add_executable` line in CMakeLists.txt to create an executable for your main program.
    
- [ ]  Write about your program in your README file. Justify the choices you made in creating the project
(which should include answers to the questions above).

- [ ] All of the above must be committed and pushed to your GitHub repository.

- [ ]  On Gradescope, submit the URL of the last commit in a submission.txt file.