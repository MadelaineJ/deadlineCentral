DROP TABLE Tasks;
DROP TABLE StudentCourses;
DROP TABLE Courses;
DROP TABLE Students;
DROP TABLE Instructors;


CREATE TABLE Students(
    userID INTEGER PRIMARY KEY,
    name VARCHAR2(50),
    email VARCHAR2(100),
    password VARCHAR2(100)
);

CREATE TABLE Instructors(
    userID INTEGER PRIMARY KEY,
    name VARCHAR2(50),
    email VARCHAR2(100),
    password VARCHAR2(100)
);

CREATE TABLE Courses(
    courseID INTEGER PRIMARY KEY,
    courseCode VARCHAR2(25) NOT NULL,
    courseName VARCHAR(55) NOT NULL,
    calendarDescription VARCHAR2(255)
);

CREATE TABLE Tasks(
    taskID INTEGER PRIMARY KEY,
    name VARCHAR2(50),
    type INTEGER,
    description VARCHAR2(255),
    dueDate DATE,
    weight float,
    isComplete NUMBER(1,0) DEFAULT 0, -- 1 true, 0 false
    courseID INTEGER,
    studentID INTEGER,
    instructorID INTEGER,
    -- only ONE ID should be entered, the others should be NULL
    CONSTRAINT UC_Course_Student_Instructor CHECK (
        (courseID IS NOT NULL AND studentID IS NULL AND instructorID IS NULL) OR
        (courseID IS NULL AND studentID IS NOT NULL AND instructorID IS NULL) OR
        (courseID IS NULL AND studentID IS NULL AND instructorID IS NOT NULL)
       ),
    CONSTRAINT fk_tasks_courses FOREIGN KEY (courseID) REFERENCES Courses(courseID),
      CONSTRAINT fk_tasks_students FOREIGN KEY (studentID) REFERENCES Students(userID),
    CONSTRAINT fk_tasks_instructors FOREIGN KEY (instructorID) REFERENCES Instructors(userID)
);


CREATE TABLE StudentCourses(
    userID INTEGER,
    courseID INTEGER,
    CONSTRAINT pk_student_courses PRIMARY KEY (userID, courseID),
    CONSTRAINT fk_student_userID FOREIGN KEY (userID) REFERENCES Students(userID),
    CONSTRAINT fk_student_courseID FOREIGN KEY (courseID) REFERENCES Courses(courseID)
);


-- DUMMY DATA ##########################################################################################

-- INSERTS 10 entries into Students & 5 into Instructors
INSERT ALL
  INTO Students(userID, name, email, password) VALUES (1, 'John Doe', 'johndoe@example.com', 'password123')
  INTO Students(userID, name, email, password) VALUES (2, 'Jane Smith', 'janesmith@example.com', 'password456')
  INTO Students(userID, name, email, password) VALUES (3, 'Bob Johnson', 'bjohnson@example.com', 'password789')
  INTO Students(userID, name, email, password) VALUES (4, 'Emily Davis', 'edavis@example.com', 'passwordabc')
  INTO Students(userID, name, email, password) VALUES (5, 'Tom Wilson', 'twilson@example.com', 'passworddef')
  INTO Students(userID, name, email, password) VALUES (6, 'Samantha Lee', 'slee@example.com', 'passwordghi')
  INTO Students(userID, name, email, password) VALUES (7, 'David Kim', 'dkim@example.com', 'passwordjkl')
  INTO Students(userID, name, email, password) VALUES (8, 'Mary Brown', 'mbrown@example.com', 'passwordmno')
  INTO Students(userID, name, email, password) VALUES (9, 'Alex Rodriguez', 'arodriguez@example.com', 'passwordpqr')
  INTO Students(userID, name, email, password) VALUES (10, 'Jessica Garcia', 'jgarcia@example.com', 'passwordstu')
  -- below are inserted into Instructors table
  INTO Instructors(userID, name, email, password) VALUES (11, 'Michael Nguyen', 'mnguyen@example.com', 'passwordvwx')
  INTO Instructors(userID, name, email, password) VALUES (12, 'Maria Hernandez', 'mhernandez@example.com', 'passwordyz1')
  INTO Instructors(userID, name, email, password) VALUES (13, 'Chris Davis', 'cdavis@example.com', 'password234')
  INTO Instructors(userID, name, email, password) VALUES (14, 'Nicole Johnson', 'njohnson@example.com', 'password567')
  INTO Instructors(userID, name, email, password) VALUES (15, 'Kevin Lee', 'klee@example.com', 'password890')
SELECT 1 FROM DUAL;



-- INSERTS 4 entries into Courses
INSERT ALL
  INTO Courses(courseID, courseCode, courseName, calendarDescription) VALUES (1, 'DS101', 'Introduction to Data Science', 'This course provides an introduction to the fundamental concepts of data science.')
  INTO Courses(courseID, courseCode, courseName, calendarDescription) VALUES (2, 'ML201', 'Machine Learning', 'This course covers the basic principles of machine learning, including supervised and unsupervised learning.')
  INTO Courses(courseID, courseCode, courseName, calendarDescription) VALUES (3, 'DV301', 'Data Visualization', 'This course explores techniques and tools for visualizing and communicating data effectively.')
  INTO Courses(courseID, courseCode, courseName, calendarDescription) VALUES (4, 'BDA401', 'Big Data Analytics', 'This course covers techniques and tools for analyzing large datasets.')
SELECT 1 FROM DUAL;



-- INSERT 8 Course-Tasks into TASKS, 10 Student-Tasks, 5 Instructor-Tasks
-- types: 1: assignment 2: test/quiz/midterm 3: final 4: participation 5: personal
-- COURSE TASKS #####################################################################################################
INSERT ALL
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (1, 'Assignment 1', '1', 'Introduction to Computer Science', TO_DATE('2022-03-14', 'YYYY-MM-DD'), 0.2, 0, 1, NULL, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (2, 'Quiz 1', '2', 'Algorithms and Data Structures', TO_DATE('2022-03-18', 'YYYY-MM-DD'), 0.1, 0, 2, NULL, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (3, 'Project 1', '1', 'Database Systems', TO_DATE('2022-03-31', 'YYYY-MM-DD'), 0.3, 0, 3, NULL, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (4, 'Midterm Exam', '3', 'Computer Networks', TO_DATE('2022-04-06', 'YYYY-MM-DD'), 0.4, 0, 4, NULL, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (5, 'Homework 2', '1', 'Introduction to Computer Science', TO_DATE('2022-04-15', 'YYYY-MM-DD'), 0.2, 0, 1, NULL, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (6, 'Quiz 2', '2', 'Algorithms and Data Structures', TO_DATE('2022-04-20', 'YYYY-MM-DD'), 0.1, 0, 2, NULL, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (7, 'Project 2', '1', 'Database Systems', TO_DATE('2022-05-05', 'YYYY-MM-DD'), 0.3, 0, 3, NULL, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (8, 'Final Exam', '3', 'Computer Networks', TO_DATE('2022-05-10', 'YYYY-MM-DD'), 0.4, 0, 4, NULL, NULL)
SELECT 1 FROM DUAL;
-- STUDENT TASKS ####################################################################################################
INSERT ALL
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (9, 'Start Homework 1', '5', 'Start Homework 1', TO_DATE('2022-03-14', 'YYYY-MM-DD'), 0.2, 0, NULL, 1, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (10, 'Study for Quiz 1', '5',  'Study for Quiz 1', TO_DATE('2022-03-18', 'YYYY-MM-DD'), 0.1, 0, NULL, 2, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (11, 'Complete Project 1', '5', 'Finish Project 1', TO_DATE('2022-03-31', 'YYYY-MM-DD'), 0.3, 0, NULL, 3, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (12, 'Midterm Exam Prep', '5', 'Prep for Midterm', TO_DATE('2022-04-06', 'YYYY-MM-DD'), 0.4, 0, NULL, 4, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (13, 'Submit Homework 2', '5', 'Hand in Homework', TO_DATE('2022-04-15', 'YYYY-MM-DD'), 0.2, 0, NULL, 5, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (14, 'Review Quiz 2', '5', 'Review Quiz 2', TO_DATE('2022-04-20', 'YYYY-MM-DD'), 0.1, 0, NULL, 6, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (15, 'Start Project 2', '5', 'Start Part of P2', TO_DATE('2022-05-05', 'YYYY-MM-DD'), 0.3, 0, NULL, 7, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (16, 'Study for Final Exam', '5', 'Read Chapters: 12, 13, 14', TO_DATE('2022-05-10', 'YYYY-MM-DD'), 0.4, 0, NULL, 8, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (17, 'Start Homework 3', '5', 'Start Homework', TO_DATE('2022-05-15', 'YYYY-MM-DD'), 0.2, 0, NULL, 9, NULL)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (18, 'Take Quiz 3', '5', 'Complete Quiz 3', TO_DATE('2022-05-15', 'YYYY-MM-DD'), 0.2, 0, NULL, 10, NULL)
SELECT 1 FROM DUAL;
-- INSTRUCTOR TASKS ################################################################################################


INSERT ALL
  INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (19, 'Mark Assignment 1', '5', 'Mark Assignments', TO_DATE('2022-03-10', 'YYYY-MM-DD'), 0.1, 0, NULL, NULL, 11)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (20, 'Mark Quiz 1', '5', 'Calculus 1', TO_DATE('2022-03-17', 'YYYY-MM-DD'), 0.1, 0, NULL, NULL, 12)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (21, 'Hand Out Homework 1', '5', 'Discrete Mathematics', TO_DATE('2022-03-22', 'YYYY-MM-DD'), 0.2, 0, NULL, NULL, 13)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (22, 'Admin Midterm Exam', '5', 'Data Structures and Algorithms', TO_DATE('2022-04-07', 'YYYY-MM-DD'), 0.3, 0, NULL, NULL, 14)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (23, 'Prepare Assignment 2', '5', 'Intro to Statistics', TO_DATE('2022-04-15', 'YYYY-MM-DD'), 0.1, 0, NULL, NULL, 15)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (24, 'Complete Quiz 2', '5', 'Calculus 1', TO_DATE('2022-04-22', 'YYYY-MM-DD'), 0.1, 0, NULL, NULL, 11)
INTO Tasks(taskID, name, type, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES
    (25, 'Return Homework 2', '5', 'Discrete Mathematics', TO_DATE('2022-05-01', 'YYYY-MM-DD'), 0.2, 0, NULL, NULL, 12)

SELECT 1 FROM DUAL;
