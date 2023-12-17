# Meeting Notes
In this file, you are required to take notes for your weekly meetings. 
In each meeting, you are required to discuss:

1. What each member has done during the week?
2. Are there challenges or problems? Discuss the possible solutions
3. Plan for the next week for everyone
4. Deviations and changes to the project plan, if any


# Meeting 30.10.2023 16:00

**Participants**: 
1. Lauri Wilppu
2. Verneri Hakkarainen
3. Teodors Kerimovs
4. Dang Ly

## Summary of works

All have done research in regarding the project topic. And Teodors came up with a work division plan. We take this open source project as an example for us: https://github.com/rogerallen/raytracinginoneweekendincuda 

## Challenges

1. Implementing a usable user interface for testing. We started thinking about possible ideas. First just haveing some camera parameters to input and after that when else is done maybe have a preview of the resulting image.
2. Learning to use git properly. Git was kind of new to everyone.

## Actions

We will start the implementation of the basic features using the open source example.

1. Teodors Kerimovs is going to implement the main, vector and background ray. Also the possible tests.
2. Dang Ly will be implementing sphere, shading and anti aliasing
3. Verneri Hakakrainen is implementing different materials and possible tests for those.
4. Lauri Wilpppu will do camera positioning and defocus blur.

> Please reflect these action decisions in your git commit messages so that 
> your group members and advisor can follow the progress.

## Project status 
The project plan is ready. Only missing a software structure picture. We now start implementing the basics.

### TODOs
From the advisor meeting:
1. Implement unit tests with the help of testing pyramid idea.
2. Do a weekly plan till the project deadline
3. Unit tests with Catch2











# Meeting 6.11.2023 17:39

**Participants**: 
1. Lauri Wilppu
2. Verneri Hakkarainen
3. Teodors Kerimovs
4. Dang Ly 

## Summary of works
Example of doxygen comment.
Unit tests with googletest runned by cmake.
Problems with Cmake solved during the meeting.
- Filepaths
- How to use cmake 
1. Teodors
   First chapters of the book and googletest.

2. Dang
   Project plan formatting and structure of the program. And git and cmake help.

3. Verneri
   Created a material branch and started to implement materials.

4. Lauri
   Created cameraclass and branch.

## Challenges

1. Cmake did not work first (resolved)
2. Git problems

## Actions
1. Verneri will implement his part after Dang
2. Dang will push his part (Written in the plan)
3. Lauri will do his part

> Please reflect these action decisions in your git commit messages so that 
> your group members and advisor can follow the progress.

## Project status 
We are a little bit out of schedule because of time, cmake and git issues. We got issues solved and should soon be on track. 




























# Meeting 13.11.2023 16::00

**Participants**: 
1. Verneri Hakkarainen 
2. Lauri Wilppu
3. Teodors Kerimovs

## Summary of works
1. Verneri

   Implemented materials.

2. Lauri

   Finished movable camera and diaelectric material.
3. ...

## Challenges

1. Where to go now since little behind plan.
2. Multiple inculde errors.

## Actions
1. Dang implementing GUI? Not present now. Needing verification.
2. Teodors reading about lightsources and unit test
3. Verneri, unit tests and reading about monte carlo
4. Lauri, unit test spheres


## Project status 
Basic ray tracing now implemented. Few basic features missing. Lightsource and GUI where the scene file can be modified.

### TODOs
Priority
1. GUI where scene file paramaters can change
2. Lightsource implementation
Additional basic features
3. More shapes


 #Meeting 29.11.2023 15:08

**Participants**: 
1. Verneri Hakkarainen
2. Teodors Kerimovs
3. Lauri Wilppu
4. Member 4 

## Summary of works
1. Teodors
   
   Implemented motion blur. Has been trying to implement Bounding Volume hierarchies. Not working and stopping implementing, because of time issues.

2. Lauri 

   Has implemented multi threading and output of jpeg image.

3. Verneri

   Has been trying to implement monte carlo. Full implementation takes too much time so implementation is stopping now.

## Challenges

Time constraints and the complexity of the project.

## Actions
1. Verneri will add lights to main. Lights are currently implemented only in monte_carlo branch.
2. Member 2 is going to work with Member 1 to use abstract interface in derived 
   monster classes.
3. Member 2 is going to test the interface.
4. Member 3 is going to use ...

> Please reflect these action decisions in your git commit messages so that 
> your group members and advisor can follow the progress.

## Project status 
We need to make code clearer and add comments and proper unit tests. GUI needs to be implemented. Right now we have to merge our changes to main.

### TODOs
1. List all technical possibilities, that our raytracer can do:

1.1. Different shapes - sphere, box, rectangles (2D);
They can be moved in 3D space to create a scene.
Shapes can be materials - metal, dielectric, lambertian.

1.2. Camera position and field of view, direction.

1.3. Change render size.

1.4. Resolution of the scene can be changed.

1.5. Additionally, spheres are movable.

1.6. ?

2. How to GUI?
Dang should follow the technical possibilities

3. Refactor (.hpp) to (.hpp and .cpp)

4. Write rest of the unit tests

5. Write documentation
Ask supervisor, what is expected.

6. Make CMAKE with flags
- run with unit tests;
- run with GUI.




# Meeting 8.12.2023 16::47

**Participants**: 
1. Lauri Wilppu
2. Teodors Kerimovs
3. Dang Ly
4. Verneri Hakkarainen

## Project status 
Last implementations and final tuning.

### TODOs
1. Final documentation, see below

2. Doxygen comments, Verneri

3. Unit tests, Everyone writes for what they've done.

4. Scenes showcasing glass, metal, lights, Verneri, Lauri 

5. GUI Dang 

6. Demo plan and meeting (next week)

7. structure check (files) Lauri

8. Export of dyxygen 2.5.2.2 (on sunday on meeting)

PLAN
1. overview, Verneri
2. Software structure, Dang
3. Instuctions for building and using, Teodors
4. How to use, Dang
5. Testing, Verneri
6. Work log, Lauri 

After completing the development, you must create a documentation for your project. The documentation should be a PDF document, and should be composed of following parts:

Overview: what the software does, what it doesn’t do? (this can be taken/updated from the project plan)

Software structure: overall architecture, class relationships diagrams, interfaces to external libraries

Instructions for building and using the software

How to compile the program (‘make’ should be sufficient), as taken from the git repository. If external libraries are needed, describe the requirements here

How to use the software: a basic user guide

Testing: how the different modules in software were tested, description of the methods and outcomes.

Work log: a detailed description of the division of work and everyone’s responsibilities. For each week, a description of what was done and roughly how many hours were used for the project by each project member.








# Meeting dd.mm.2021 HH::MM

**Participants**: 
1. Member 1
2. Member 2
3. Member 3
4. Member 4 

## Summary of works
1. Member 1 
   
   Implementing the class XX. Tested the class XX. 
   Results are in `tests/<class-xx-tests>`. Resolved the identified problems.

2. Member 2

   Same as above

3. ...

## Challenges

1. The integration of UI with the monsters requires an abstract interface.
2. ...

## Actions
1. Member 1 is going to look into defining an abstract interface for monsters 
   to enable easy UI integration.
2. Member 2 is going to work with Member 1 to use abstract interface in derived 
   monster classes.
3. Member 2 is going to test the interface.
4. Member 3 is going to use ...

> Please reflect these action decisions in your git commit messages so that 
> your group members and advisor can follow the progress.

## Project status 
Short summary of current project status. 

### TODOs
1. Member 1: Write an action.
2. ...

