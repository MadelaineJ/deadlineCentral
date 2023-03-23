-- Text file for CSCI375 Database Creation
DROP TABLE Tasks;
DROP TABLE StudentCourses;
DROP TABLE Courses;
DROP TABLE Students;
DROP TABLE Instructors;


CREATE TABLE Students(
    studentID INTEGER PRIMARY KEY,
    name VARCHAR2(50),
    email VARCHAR2(100),
    password VARCHAR2(100)
);

CREATE TABLE Instructors(
    instructorID INTEGER PRIMARY KEY,
    name VARCHAR2(50),
    email VARCHAR2(100),
    password VARCHAR2(100)
);

CREATE TABLE Courses(
    courseID INTEGER PRIMARY KEY,
    courseCode VARCHAR2(25) NOT NULL,
    courseName VARCHAR(55) NOT NULL,
    calendarDescription VARCHAR2(550),
    instructorID INTEGER,
    CONSTRAINT fk_courses_instructors FOREIGN KEY (instructorID) REFERENCES Instructors(instructorID)
);

CREATE TABLE Tasks(
    taskID INTEGER PRIMARY KEY,
    type INTEGER,
    name VARCHAR2(50),
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
      CONSTRAINT fk_tasks_students FOREIGN KEY (studentID) REFERENCES Students(studentID),
    CONSTRAINT fk_tasks_instructors FOREIGN KEY (instructorID) REFERENCES Instructors(instructorID)
);


CREATE TABLE StudentCourses(
    studentID INTEGER,
    courseID INTEGER,
    CONSTRAINT pk_student_courses PRIMARY KEY (studentID, courseID),
    CONSTRAINT fk_student_studentID FOREIGN KEY (studentID) REFERENCES Students(studentID),
    CONSTRAINT fk_student_courseID FOREIGN KEY (courseID) REFERENCES Courses(courseID)
);


-- DUMMY DATA ##########################################################################################

-- 100 STUDENTS
INSERT INTO Students (studentID, name, email, password) VALUES (101, 'Carman Gravel', 'CarmanGravel@example.com', 'passwordCar');
INSERT INTO Students (studentID, name, email, password) VALUES (102, 'Brent Ladouceur', 'BrentLadouceur@example.com', 'passwordBre');
INSERT INTO Students (studentID, name, email, password) VALUES (103, 'Eddie Stewart', 'EddieStewart@example.com', 'passwordEdd');
INSERT INTO Students (studentID, name, email, password) VALUES (104, 'Helena Viau', 'HelenaViau@example.com', 'passwordHel');
INSERT INTO Students (studentID, name, email, password) VALUES (105, 'Norman Godin', 'NormanGodin@example.com', 'passwordNor');
INSERT INTO Students (studentID, name, email, password) VALUES (106, 'Michel Marshall', 'MichelMarshall@example.com', 'passwordMic');
INSERT INTO Students (studentID, name, email, password) VALUES (107, 'Catherine Cummings', 'CatherineCummings@example.com', 'passwordCat');
INSERT INTO Students (studentID, name, email, password) VALUES (108, 'Christine Hudson', 'ChristineHudson@example.com', 'passwordChr');
INSERT INTO Students (studentID, name, email, password) VALUES (109, 'Fred Dick', 'FredDick@example.com', 'passwordFre');
INSERT INTO Students (studentID, name, email, password) VALUES (110, 'Glenda Forbes', 'GlendaForbes@example.com', 'passwordGle');
INSERT INTO Students (studentID, name, email, password) VALUES (111, 'William Lowe', 'WilliamLowe@example.com', 'passwordWil');
INSERT INTO Students (studentID, name, email, password) VALUES (112, 'Jeff Marsh', 'JeffMarsh@example.com', 'passwordJef');
INSERT INTO Students (studentID, name, email, password) VALUES (113, 'Josephine Donovan', 'JosephineDonovan@example.com', 'passwordJos');
INSERT INTO Students (studentID, name, email, password) VALUES (114, 'Martha Wall', 'MarthaWall@example.com', 'passwordMar');
INSERT INTO Students (studentID, name, email, password) VALUES (115, 'Ingrid Rose', 'IngridRose@example.com', 'passwordIng');
INSERT INTO Students (studentID, name, email, password) VALUES (116, 'Pierre Huang', 'PierreHuang@example.com', 'passwordPie');
INSERT INTO Students (studentID, name, email, password) VALUES (117, 'Chuck Gervais', 'ChuckGervais@example.com', 'passwordChu');
INSERT INTO Students (studentID, name, email, password) VALUES (118, 'Brittany Cantin', 'BrittanyCantin@example.com', 'passwordBri');
INSERT INTO Students (studentID, name, email, password) VALUES (119, 'Amber Guay', 'AmberGuay@example.com', 'passwordAmb');
INSERT INTO Students (studentID, name, email, password) VALUES (120, 'Merle MacKinnon', 'MerleMacKinnon@example.com', 'passwordMer');
INSERT INTO Students (studentID, name, email, password) VALUES (121, 'Alan Piche', 'AlanPiche@example.com', 'passwordAla');
INSERT INTO Students (studentID, name, email, password) VALUES (122, 'Susanne Theriault', 'SusanneTheriault@example.com', 'passwordSus');
INSERT INTO Students (studentID, name, email, password) VALUES (123, 'Germaine Lacombe', 'GermaineLacombe@example.com', 'passwordGer');
INSERT INTO Students (studentID, name, email, password) VALUES (124, 'Benjamin Talbot', 'BenjaminTalbot@example.com', 'passwordBen');
INSERT INTO Students (studentID, name, email, password) VALUES (125, 'Curtis Burns', 'CurtisBurns@example.com', 'passwordCur');
INSERT INTO Students (studentID, name, email, password) VALUES (126, 'Annette Jacobs', 'AnnetteJacobs@example.com', 'passwordAnn');
INSERT INTO Students (studentID, name, email, password) VALUES (127, 'Stuart Hughes', 'StuartHughes@example.com', 'passwordStu');
INSERT INTO Students (studentID, name, email, password) VALUES (128, 'Tania Charron', 'TaniaCharron@example.com', 'passwordTan');
INSERT INTO Students (studentID, name, email, password) VALUES (129, 'Jodi James', 'JodiJames@example.com', 'passwordJod');
INSERT INTO Students (studentID, name, email, password) VALUES (130, 'Reginald Bradley', 'ReginaldBradley@example.com', 'passwordReg');
INSERT INTO Students (studentID, name, email, password) VALUES (131, 'Felix McCallum', 'FelixMcCallum@example.com', 'passwordFel');
INSERT INTO Students (studentID, name, email, password) VALUES (132, 'Jean-Guy Gagnon', 'Jean-GuyGagnon@example.com', 'passwordJea');
INSERT INTO Students (studentID, name, email, password) VALUES (133, 'Gayle Doiron', 'GayleDoiron@example.com', 'passwordGay');
INSERT INTO Students (studentID, name, email, password) VALUES (134, 'Jayne Butler', 'JayneButler@example.com', 'passwordJay');
INSERT INTO Students (studentID, name, email, password) VALUES (135, 'Alain Kelly', 'AlainKelly@example.com', 'passwordAla');
INSERT INTO Students (studentID, name, email, password) VALUES (136, 'Jamie Milne', 'JamieMilne@example.com', 'passwordJam');
INSERT INTO Students (studentID, name, email, password) VALUES (137, 'Edna Daigle', 'EdnaDaigle@example.com', 'passwordEdn');
INSERT INTO Students (studentID, name, email, password) VALUES (138, 'Olivier English', 'OlivierEnglish@example.com', 'passwordOli');
INSERT INTO Students (studentID, name, email, password) VALUES (139, 'Yvette Pilon', 'YvettePilon@example.com', 'passwordYve');
INSERT INTO Students (studentID, name, email, password) VALUES (140, 'Rodney Chouinard', 'RodneyChouinard@example.com', 'passwordRod');
INSERT INTO Students (studentID, name, email, password) VALUES (141, 'Gene Davidson', 'GeneDavidson@example.com', 'passwordGen');
INSERT INTO Students (studentID, name, email, password) VALUES (142, 'Melissa McRae', 'MelissaMcRae@example.com', 'passwordMel');
INSERT INTO Students (studentID, name, email, password) VALUES (143, 'Charmaine Turgeon', 'CharmaineTurgeon@example.com', 'passwordCha');
INSERT INTO Students (studentID, name, email, password) VALUES (144, 'Lucie Gardner', 'LucieGardner@example.com', 'passwordLuc');
INSERT INTO Students (studentID, name, email, password) VALUES (145, 'Jeannie Gendron', 'JeannieGendron@example.com', 'passwordJea');
INSERT INTO Students (studentID, name, email, password) VALUES (146, 'Rosaire Young', 'RosaireYoung@example.com', 'passwordRos');
INSERT INTO Students (studentID, name, email, password) VALUES (147, 'Agnes Cameron', 'AgnesCameron@example.com', 'passwordAgn');
INSERT INTO Students (studentID, name, email, password) VALUES (148, 'Brendan Maltais', 'BrendanMaltais@example.com', 'passwordBre');
INSERT INTO Students (studentID, name, email, password) VALUES (149, 'Bertha Guillemette', 'BerthaGuillemette@example.com', 'passwordBer');
INSERT INTO Students (studentID, name, email, password) VALUES (150, 'Carl Phillips', 'CarlPhillips@example.com', 'passwordCar');
INSERT INTO Students (studentID, name, email, password) VALUES (151, 'Felix Germain', 'FelixGermain@example.com', 'passwordFel');
INSERT INTO Students (studentID, name, email, password) VALUES (152, 'Jordan Mercer', 'JordanMercer@example.com', 'passwordJor');
INSERT INTO Students (studentID, name, email, password) VALUES (153, 'Donald Labelle', 'DonaldLabelle@example.com', 'passwordDon');
INSERT INTO Students (studentID, name, email, password) VALUES (154, 'Chas Vaillancourt', 'ChasVaillancourt@example.com', 'passwordCha');
INSERT INTO Students (studentID, name, email, password) VALUES (155, 'Victor Pratt', 'VictorPratt@example.com', 'passwordVic');
INSERT INTO Students (studentID, name, email, password) VALUES (156, 'Jane Kerr', 'JaneKerr@example.com', 'passwordJan');
INSERT INTO Students (studentID, name, email, password) VALUES (157, 'Vicky Levasseur', 'VickyLevasseur@example.com', 'passwordVic');
INSERT INTO Students (studentID, name, email, password) VALUES (158, 'Cheryl Lloyd', 'CherylLloyd@example.com', 'passwordChe');
INSERT INTO Students (studentID, name, email, password) VALUES (159, 'Grace Chan', 'GraceChan@example.com', 'passwordGra');
INSERT INTO Students (studentID, name, email, password) VALUES (160, 'Brett Schmidt', 'BrettSchmidt@example.com', 'passwordBre');
INSERT INTO Students (studentID, name, email, password) VALUES (161, 'Ginette Sanderson', 'GinetteSanderson@example.com', 'passwordGin');
INSERT INTO Students (studentID, name, email, password) VALUES (162, 'Leona Campbell', 'LeonaCampbell@example.com', 'passwordLeo');
INSERT INTO Students (studentID, name, email, password) VALUES (163, 'Aaron Frenette', 'AaronFrenette@example.com', 'passwordAar');
INSERT INTO Students (studentID, name, email, password) VALUES (164, 'Nadine Gill', 'NadineGill@example.com', 'passwordNad');
INSERT INTO Students (studentID, name, email, password) VALUES (165, 'Jean-Claude Berry', 'Jean-ClaudeBerry@example.com', 'passwordJea');
INSERT INTO Students (studentID, name, email, password) VALUES (166, 'Melissa Tait', 'MelissaTait@example.com', 'passwordMel');
INSERT INTO Students (studentID, name, email, password) VALUES (167, 'Taylor Beauchemin', 'TaylorBeauchemin@example.com', 'passwordTay');
INSERT INTO Students (studentID, name, email, password) VALUES (168, 'Donna Gervais', 'DonnaGervais@example.com', 'passwordDon');
INSERT INTO Students (studentID, name, email, password) VALUES (169, 'Rolland Clement', 'RollandClement@example.com', 'passwordRol');
INSERT INTO Students (studentID, name, email, password) VALUES (170, 'Kristin Dunlop', 'KristinDunlop@example.com', 'passwordKri');
INSERT INTO Students (studentID, name, email, password) VALUES (171, 'Emma Nielsen', 'EmmaNielsen@example.com', 'passwordEmm');
INSERT INTO Students (studentID, name, email, password) VALUES (172, 'Mark Paul', 'MarkPaul@example.com', 'passwordMar');
INSERT INTO Students (studentID, name, email, password) VALUES (173, 'Allan Meyer', 'AllanMeyer@example.com', 'passwordAll');
INSERT INTO Students (studentID, name, email, password) VALUES (174, 'Marsha McCann', 'MarshaMcCann@example.com', 'passwordMar');
INSERT INTO Students (studentID, name, email, password) VALUES (175, 'Isabelle Bourassa', 'IsabelleBourassa@example.com', 'passwordIsa');
INSERT INTO Students (studentID, name, email, password) VALUES (176, 'Rhonda Hebert', 'RhondaHebert@example.com', 'passwordRho');
INSERT INTO Students (studentID, name, email, password) VALUES (177, 'Theresa Cummings', 'TheresaCummings@example.com', 'passwordThe');
INSERT INTO Students (studentID, name, email, password) VALUES (178, 'Paulette Doyon', 'PauletteDoyon@example.com', 'passwordPau');
INSERT INTO Students (studentID, name, email, password) VALUES (179, 'Clement Cardinal', 'ClementCardinal@example.com', 'passwordCle');
INSERT INTO Students (studentID, name, email, password) VALUES (180, 'Cody Drouin', 'CodyDrouin@example.com', 'passwordCod');
INSERT INTO Students (studentID, name, email, password) VALUES (181, 'Conrad Dionne', 'ConradDionne@example.com', 'passwordCon');
INSERT INTO Students (studentID, name, email, password) VALUES (182, 'Aline Glover', 'AlineGlover@example.com', 'passwordAli');
INSERT INTO Students (studentID, name, email, password) VALUES (183, 'Ernest Chapman', 'ErnestChapman@example.com', 'passwordErn');
INSERT INTO Students (studentID, name, email, password) VALUES (184, 'Cindy Sinclair', 'CindySinclair@example.com', 'passwordCin');
INSERT INTO Students (studentID, name, email, password) VALUES (185, 'Sherry Wilkinson', 'SherryWilkinson@example.com', 'passwordShe');
INSERT INTO Students (studentID, name, email, password) VALUES (186, 'Marcus Singh', 'MarcusSingh@example.com', 'passwordMar');
INSERT INTO Students (studentID, name, email, password) VALUES (187, 'Rita Giles', 'RitaGiles@example.com', 'passwordRit');
INSERT INTO Students (studentID, name, email, password) VALUES (188, 'Yannick Tetreault', 'YannickTetreault@example.com', 'passwordYan');
INSERT INTO Students (studentID, name, email, password) VALUES (189, 'Judith Brar', 'JudithBrar@example.com', 'passwordJud');
INSERT INTO Students (studentID, name, email, password) VALUES (190, 'Marlene McMahon', 'MarleneMcMahon@example.com', 'passwordMar');
INSERT INTO Students (studentID, name, email, password) VALUES (191, 'Fatima Greene', 'FatimaGreene@example.com', 'passwordFat');
INSERT INTO Students (studentID, name, email, password) VALUES (192, 'Pierrette Fung', 'PierretteFung@example.com', 'passwordPie');
INSERT INTO Students (studentID, name, email, password) VALUES (193, 'Rosaire Simpson', 'RosaireSimpson@example.com', 'passwordRos');
INSERT INTO Students (studentID, name, email, password) VALUES (194, 'Merle Huang', 'MerleHuang@example.com', 'passwordMer');
INSERT INTO Students (studentID, name, email, password) VALUES (195, 'Jodi Norman', 'JodiNorman@example.com', 'passwordJod');
INSERT INTO Students (studentID, name, email, password) VALUES (196, 'Ghislain McLeod', 'GhislainMcLeod@example.com', 'passwordGhi');
INSERT INTO Students (studentID, name, email, password) VALUES (197, 'Naomi Hodgson', 'NaomiHodgson@example.com', 'passwordNao');
INSERT INTO Students (studentID, name, email, password) VALUES (198, 'Kris Hill', 'KrisHill@example.com', 'passwordKri');
INSERT INTO Students (studentID, name, email, password) VALUES (199, 'Yolande Durand', 'YolandeDurand@example.com', 'passwordYol');
INSERT INTO Students (studentID, name, email, password) VALUES (200, 'Marie-Eve Cunningham', 'Marie-EveCunningham@example.com', 'passwordMar');


-- 6 INSTRUCTORS
INSERT INTO Instructors (instructorID, name, email, password) VALUES (1001, 'Rorie Gabrielson', 'RorieGabrielson@example.com', 'passwordRor');
INSERT INTO Instructors (instructorID, name, email, password) VALUES (1002, 'Eli Selby', 'EliSelby@example.com', 'passwordEli');
INSERT INTO Instructors (instructorID, name, email, password) VALUES (1003, 'Ezra Lane', 'EzraLane@example.com', 'passwordEzr');
INSERT INTO Instructors (instructorID, name, email, password) VALUES (1004, 'Isabella Newton', 'IsabellaNewton@example.com', 'passwordIsa');
INSERT INTO Instructors (instructorID, name, email, password) VALUES (1005, 'Brayden Hanson', 'BraydenHanson@example.com', 'passwordBra');
INSERT INTO Instructors (instructorID, name, email, password) VALUES (1006, 'Darcy Harper', 'DarcyHarper@example.com', 'passwordDar');


-- 12 COURSES
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2000, 'CSCI251', 'Systems and Networks', 'An introduction to operating systems and computer networks. Topics include network architectures, communications protocols, client / server architecture and file systems. The lab component includes hardware and software installations, upgrades and backups. (3:0:2)', 1001);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2001, 'CSCI265', 'Software Engineering', 'An exploration of the methods and tools for developing high quality software. The course includes topics in program design, program style, algorithm selection, interface design, debugging and testing, system utilities, version control, regular expressions and an introduction to scripting languages. (4:0:1)', 1001);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2002, 'CSCI 260', 'Data Structures', 'An examination of various methods of representing and manipulating data, including internal representation of data, stacks, queues, linked lists, trees and graphs. Analysis of algorithms will also be discussed extensively. (4:0:1)', 1001);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2003, 'CSCI 310', 'Introduction to Human-Computer Interaction', 'An introduction to understanding human behaviour as it applies to interface design, implementation, and evaluation. Topics include: design issues and goals, the limits of the human cognitive system, user-centered design, prototyping, establishing requirements, evaluation techniques, and design implications of emerging technologies. (3:0:1)', 1001);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2004, 'CSCI 311', 'Web Programming', 'Exploration of languages, tools and techniques to write software for use within the World Wide Web (WWW). The course includes the WWW client/server model and related protocols, web server properties, web markup languages, client/server scripting tools, server side programming, and database access tools. (3:0:2)', 1002);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2005, 'CSCI 320', 'Foundations of Computer Science', 'A survey of formal models and results that form the theoretical foundation of computer science. Typical topics include finite automata, Turing machines, simple undecidable problems, context-free languages, grammars and elementary computational complexity. (3:1:0)', 1002);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2006, 'CSCI 330', 'Programming Languages', 'The fundamental concepts of imperative and applicative programming languages. Topics include the description of data types, variable assignment and sharing, sequencing, iteration and recursion, parameter passing mechanisms, and type checking. (3:0:1)', 1002);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2007, 'CSCI 331', 'Object-Oriented Software Development', 'Topics include aspects of object-oriented analysis, design and development; definition and comparison of object-oriented metrics; verification methods for OO-software; maintenance and reuse issues. (3:0:1)', 1003);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2008, 'CSCI 355', 'Digital Logic and Computer Organization', 'The fundamentals of logic design, computer organization, and the structure of major hardware components of computers. Topics include the application of Boolean algebra to switching circuits; the use of MSI, LSI and field programmable devices in digital design; combinatorial and sequential circuits, flip flops, counters, memory organization, CAD tools. (3:0:2)', 1003);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2009, 'CSCI 360', 'Intro to Operating Systems', 'An introduction to the major concepts of operating systems and study of the interrelationships between the operating system and the architecture of computer systems. Topics include operating system structures, concurrent programming techniques, cpu scheduling, deadlocks, memory management, file systems and protection. (3:0:1)', 1004);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2010, 'CSCI 370', 'Database Systems', 'An introduction to the use and operating principles of database management systems. Topics include data entities and relationships, data modelling using Entity-Relationship Diagrams, hierarchical, network and relational models of databases, query language, physical representation of data in secondary storage, relational algebra and calculus as applied to the design of databases, security and integrity in the context of concurrent use, and basic ethical issues associated with database design and use. (3:0:1)', 1005);
INSERT INTO Courses (courseID, courseCode, courseName, calendarDescription, instructorID) VALUES (2011, 'MATH 123', 'Logic and Foundations', 'An introduction to higher level mathematical thinking and techniques vital for success in mathematics and computer science. Topics include fundamental counting principles, combinations and permutations, symbolic logic, set theory, elementary number theory, one-to-one and onto functions. Essential mathematical proof techniques are emphasized: direct proof, proof by contradiction and mathematical induction. (4:0:0)', 1006);


-- 300 STUDENTCOURSES (SUBSCRIPTIONS)
INSERT INTO StudentCourses (studentID, courseID) VALUES (101, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (101, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (101, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (102, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (102, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (102, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (103, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (103, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (103, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (104, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (104, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (104, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (105, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (105, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (105, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (106, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (106, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (106, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (107, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (107, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (107, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (108, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (108, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (108, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (109, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (109, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (109, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (110, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (110, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (110, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (111, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (111, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (111, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (112, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (112, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (112, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (113, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (113, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (113, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (114, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (114, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (114, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (115, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (115, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (115, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (116, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (116, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (116, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (117, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (117, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (117, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (118, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (118, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (118, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (119, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (119, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (119, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (120, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (120, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (120, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (121, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (121, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (121, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (122, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (122, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (122, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (123, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (123, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (123, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (124, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (124, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (124, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (125, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (125, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (125, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (126, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (126, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (126, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (127, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (127, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (127, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (128, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (128, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (128, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (129, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (129, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (129, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (130, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (130, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (130, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (131, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (131, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (131, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (132, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (132, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (132, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (133, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (133, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (133, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (134, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (134, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (134, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (135, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (135, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (135, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (136, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (136, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (136, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (137, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (137, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (137, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (138, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (138, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (138, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (139, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (139, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (139, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (140, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (140, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (140, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (141, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (141, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (141, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (142, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (142, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (142, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (143, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (143, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (143, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (144, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (144, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (144, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (145, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (145, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (145, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (146, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (146, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (146, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (147, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (147, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (147, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (148, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (148, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (148, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (149, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (149, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (149, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (150, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (150, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (150, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (151, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (151, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (151, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (152, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (152, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (152, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (153, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (153, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (153, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (154, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (154, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (154, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (155, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (155, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (155, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (156, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (156, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (156, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (157, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (157, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (157, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (158, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (158, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (158, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (159, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (159, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (159, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (160, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (160, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (160, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (161, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (161, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (161, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (162, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (162, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (162, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (163, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (163, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (163, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (164, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (164, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (164, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (165, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (165, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (165, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (166, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (166, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (166, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (167, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (167, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (167, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (168, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (168, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (168, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (169, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (169, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (169, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (170, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (170, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (170, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (171, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (171, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (171, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (172, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (172, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (172, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (173, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (173, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (173, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (174, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (174, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (174, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (175, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (175, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (175, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (176, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (176, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (176, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (177, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (177, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (177, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (178, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (178, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (178, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (179, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (179, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (179, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (180, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (180, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (180, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (181, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (181, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (181, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (182, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (182, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (182, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (183, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (183, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (183, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (184, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (184, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (184, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (185, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (185, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (185, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (186, 2000);
INSERT INTO StudentCourses (studentID, courseID) VALUES (186, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (186, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (187, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (187, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (187, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (188, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (188, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (188, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (189, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (189, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (189, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (190, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (190, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (190, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (191, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (191, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (191, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (192, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (192, 2006);
INSERT INTO StudentCourses (studentID, courseID) VALUES (192, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (193, 2007);
INSERT INTO StudentCourses (studentID, courseID) VALUES (193, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (193, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (194, 2008);
INSERT INTO StudentCourses (studentID, courseID) VALUES (194, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (194, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (195, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (195, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (195, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (196, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (196, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (196, 2005);
INSERT INTO StudentCourses (studentID, courseID) VALUES (197, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (197, 2004);
INSERT INTO StudentCourses (studentID, courseID) VALUES (197, 2009);
INSERT INTO StudentCourses (studentID, courseID) VALUES (198, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (198, 2002);
INSERT INTO StudentCourses (studentID, courseID) VALUES (198, 2001);
INSERT INTO StudentCourses (studentID, courseID) VALUES (199, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (199, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (199, 2003);
INSERT INTO StudentCourses (studentID, courseID) VALUES (200, 2011);
INSERT INTO StudentCourses (studentID, courseID) VALUES (200, 2010);
INSERT INTO StudentCourses (studentID, courseID) VALUES (200, 2008);


-- 72 COURSE-TASKS
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (1, 0, 'CSCI 251 Participation', ' Participation task for CSCI 251 due on January 07', TO_DATE('01/07/2023', 'MM-DD-YYYY'), 0.05, 0, 2000, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (2, 1, 'CSCI 251 Assignment', ' Assignment task for CSCI 251 due on February 02', TO_DATE('02/02/2023', 'MM-DD-YYYY'), 0.1, 0, 2000, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (3, 2, 'CSCI 251 Project', ' Project task for CSCI 251 due on January 17', TO_DATE('01/17/2023', 'MM-DD-YYYY'), 0.15, 0, 2000, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (4, 3, 'CSCI 251 Quiz', ' Quiz task for CSCI 251 due on April 04', TO_DATE('04/04/2023', 'MM-DD-YYYY'), 0.2, 0, 2000, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (5, 4, 'CSCI 251 Midterm', ' Midterm task for CSCI 251 due on February 24', TO_DATE('02/24/2023', 'MM-DD-YYYY'), 0.25, 0, 2000, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (6, 5, 'CSCI 251 Final Exam', ' Final Exam task for CSCI 251 due on April 13', TO_DATE('04/13/2023', 'MM-DD-YYYY'), 0.5, 0, 2000, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (7, 0, 'CSCI 265 Participation', ' Participation task for CSCI 265 due on January 07', TO_DATE('01/07/2023', 'MM-DD-YYYY'), 0.05, 0, 2001, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (8, 1, 'CSCI 265 Assignment', ' Assignment task for CSCI 265 due on February 21', TO_DATE('02/21/2023', 'MM-DD-YYYY'), 0.1, 0, 2001, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (9, 2, 'CSCI 265 Project', ' Project task for CSCI 265 due on February 22', TO_DATE('02/22/2023', 'MM-DD-YYYY'), 0.15, 0, 2001, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (10, 3, 'CSCI 265 Quiz', ' Quiz task for CSCI 265 due on March 29', TO_DATE('03/29/2023', 'MM-DD-YYYY'), 0.2, 0, 2001, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (11, 4, 'CSCI 265 Midterm', ' Midterm task for CSCI 265 due on March 28', TO_DATE('03/28/2023', 'MM-DD-YYYY'), 0.25, 0, 2001, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (12, 5, 'CSCI 265 Final Exam', ' Final Exam task for CSCI 265 due on April 16', TO_DATE('04/16/2023', 'MM-DD-YYYY'), 0.5, 0, 2001, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (13, 0, 'CSCI 260 Participation', ' Participation task for CSCI 260 due on February 26', TO_DATE('02/26/2023', 'MM-DD-YYYY'), 0.05, 0, 2002, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (14, 1, 'CSCI 260 Assignment', ' Assignment task for CSCI 260 due on April 01', TO_DATE('04/01/2023', 'MM-DD-YYYY'), 0.1, 0, 2002, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (15, 2, 'CSCI 260 Project', ' Project task for CSCI 260 due on January 17', TO_DATE('01/17/2023', 'MM-DD-YYYY'), 0.15, 0, 2002, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (16, 3, 'CSCI 260 Quiz', ' Quiz task for CSCI 260 due on January 23', TO_DATE('01/23/2023', 'MM-DD-YYYY'), 0.2, 0, 2002, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (17, 4, 'CSCI 260 Midterm', ' Midterm task for CSCI 260 due on February 15', TO_DATE('02/15/2023', 'MM-DD-YYYY'), 0.25, 0, 2002, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (18, 5, 'CSCI 260 Final Exam', ' Final Exam task for CSCI 260 due on April 20', TO_DATE('04/20/2023', 'MM-DD-YYYY'), 0.5, 0, 2002, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (19, 0, 'CSCI 310 Participation', ' Participation task for CSCI 310 due on January 24', TO_DATE('01/24/2023', 'MM-DD-YYYY'), 0.05, 0, 2003, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (20, 1, 'CSCI 310 Assignment', ' Assignment task for CSCI 310 due on January 26', TO_DATE('01/26/2023', 'MM-DD-YYYY'), 0.1, 0, 2003, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (21, 2, 'CSCI 310 Project', ' Project task for CSCI 310 due on February 08', TO_DATE('02/08/2023', 'MM-DD-YYYY'), 0.15, 0, 2003, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (22, 3, 'CSCI 310 Quiz', ' Quiz task for CSCI 310 due on January 30', TO_DATE('01/30/2023', 'MM-DD-YYYY'), 0.2, 0, 2003, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (23, 4, 'CSCI 310 Midterm', ' Midterm task for CSCI 310 due on March 06', TO_DATE('03/06/2023', 'MM-DD-YYYY'), 0.25, 0, 2003, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (24, 5, 'CSCI 310 Final Exam', ' Final Exam task for CSCI 310 due on April 17', TO_DATE('04/17/2023', 'MM-DD-YYYY'), 0.5, 0, 2003, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (25, 0, 'CSCI 311 Participation', ' Participation task for CSCI 311 due on March 01', TO_DATE('03/01/2023', 'MM-DD-YYYY'), 0.05, 0, 2004, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (26, 1, 'CSCI 311 Assignment', ' Assignment task for CSCI 311 due on March 26', TO_DATE('03/26/2023', 'MM-DD-YYYY'), 0.1, 0, 2004, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (27, 2, 'CSCI 311 Project', ' Project task for CSCI 311 due on January 14', TO_DATE('01/14/2023', 'MM-DD-YYYY'), 0.15, 0, 2004, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (28, 3, 'CSCI 311 Quiz', ' Quiz task for CSCI 311 due on January 11', TO_DATE('01/11/2023', 'MM-DD-YYYY'), 0.2, 0, 2004, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (29, 4, 'CSCI 311 Midterm', ' Midterm task for CSCI 311 due on February 08', TO_DATE('02/08/2023', 'MM-DD-YYYY'), 0.25, 0, 2004, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (30, 5, 'CSCI 311 Final Exam', ' Final Exam task for CSCI 311 due on April 19', TO_DATE('04/19/2023', 'MM-DD-YYYY'), 0.5, 0, 2004, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (31, 0, 'CSCI 320 Participation', ' Participation task for CSCI 320 due on March 01', TO_DATE('03/01/2023', 'MM-DD-YYYY'), 0.05, 0, 2005, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (32, 1, 'CSCI 320 Assignment', ' Assignment task for CSCI 320 due on March 03', TO_DATE('03/03/2023', 'MM-DD-YYYY'), 0.1, 0, 2005, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (33, 2, 'CSCI 320 Project', ' Project task for CSCI 320 due on February 08', TO_DATE('02/08/2023', 'MM-DD-YYYY'), 0.15, 0, 2005, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (34, 3, 'CSCI 320 Quiz', ' Quiz task for CSCI 320 due on January 09', TO_DATE('01/09/2023', 'MM-DD-YYYY'), 0.2, 0, 2005, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (35, 4, 'CSCI 320 Midterm', ' Midterm task for CSCI 320 due on March 13', TO_DATE('03/13/2023', 'MM-DD-YYYY'), 0.25, 0, 2005, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (36, 5, 'CSCI 320 Final Exam', ' Final Exam task for CSCI 320 due on April 21', TO_DATE('04/21/2023', 'MM-DD-YYYY'), 0.5, 0, 2005, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (37, 0, 'CSCI 330 Participation', ' Participation task for CSCI 330 due on February 04', TO_DATE('02/04/2023', 'MM-DD-YYYY'), 0.05, 0, 2006, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (38, 1, 'CSCI 330 Assignment', ' Assignment task for CSCI 330 due on March 03', TO_DATE('03/03/2023', 'MM-DD-YYYY'), 0.1, 0, 2006, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (39, 2, 'CSCI 330 Project', ' Project task for CSCI 330 due on February 01', TO_DATE('02/01/2023', 'MM-DD-YYYY'), 0.15, 0, 2006, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (40, 3, 'CSCI 330 Quiz', ' Quiz task for CSCI 330 due on February 27', TO_DATE('02/27/2023', 'MM-DD-YYYY'), 0.2, 0, 2006, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (41, 4, 'CSCI 330 Midterm', ' Midterm task for CSCI 330 due on February 25', TO_DATE('02/25/2023', 'MM-DD-YYYY'), 0.25, 0, 2006, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (42, 5, 'CSCI 330 Final Exam', ' Final Exam task for CSCI 330 due on April 11', TO_DATE('04/11/2023', 'MM-DD-YYYY'), 0.5, 0, 2006, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (43, 0, 'CSCI 331 Participation', ' Participation task for CSCI 331 due on February 03', TO_DATE('02/03/2023', 'MM-DD-YYYY'), 0.05, 0, 2007, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (44, 1, 'CSCI 331 Assignment', ' Assignment task for CSCI 331 due on March 07', TO_DATE('03/07/2023', 'MM-DD-YYYY'), 0.1, 0, 2007, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (45, 2, 'CSCI 331 Project', ' Project task for CSCI 331 due on January 06', TO_DATE('01/06/2023', 'MM-DD-YYYY'), 0.15, 0, 2007, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (46, 3, 'CSCI 331 Quiz', ' Quiz task for CSCI 331 due on March 05', TO_DATE('03/05/2023', 'MM-DD-YYYY'), 0.2, 0, 2007, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (47, 4, 'CSCI 331 Midterm', ' Midterm task for CSCI 331 due on March 15', TO_DATE('03/15/2023', 'MM-DD-YYYY'), 0.25, 0, 2007, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (48, 5, 'CSCI 331 Final Exam', ' Final Exam task for CSCI 331 due on April 23', TO_DATE('04/23/2023', 'MM-DD-YYYY'), 0.5, 0, 2007, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (49, 0, 'CSCI 355 Participation', ' Participation task for CSCI 355 due on January 01', TO_DATE('01/01/2023', 'MM-DD-YYYY'), 0.05, 0, 2008, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (50, 1, 'CSCI 355 Assignment', ' Assignment task for CSCI 355 due on March 27', TO_DATE('03/27/2023', 'MM-DD-YYYY'), 0.1, 0, 2008, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (51, 2, 'CSCI 355 Project', ' Project task for CSCI 355 due on February 14', TO_DATE('02/14/2023', 'MM-DD-YYYY'), 0.15, 0, 2008, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (52, 3, 'CSCI 355 Quiz', ' Quiz task for CSCI 355 due on March 13', TO_DATE('03/13/2023', 'MM-DD-YYYY'), 0.2, 0, 2008, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (53, 4, 'CSCI 355 Midterm', ' Midterm task for CSCI 355 due on March 26', TO_DATE('03/26/2023', 'MM-DD-YYYY'), 0.25, 0, 2008, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (54, 5, 'CSCI 355 Final Exam', ' Final Exam task for CSCI 355 due on March 31', TO_DATE('03/31/2023', 'MM-DD-YYYY'), 0.5, 0, 2008, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (55, 0, 'CSCI 360 Participation', ' Participation task for CSCI 360 due on February 01', TO_DATE('02/01/2023', 'MM-DD-YYYY'), 0.05, 0, 2009, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (56, 1, 'CSCI 360 Assignment', ' Assignment task for CSCI 360 due on January 08', TO_DATE('01/08/2023', 'MM-DD-YYYY'), 0.1, 0, 2009, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (57, 2, 'CSCI 360 Project', ' Project task for CSCI 360 due on January 05', TO_DATE('01/05/2023', 'MM-DD-YYYY'), 0.15, 0, 2009, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (58, 3, 'CSCI 360 Quiz', ' Quiz task for CSCI 360 due on February 11', TO_DATE('02/11/2023', 'MM-DD-YYYY'), 0.2, 0, 2009, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (59, 4, 'CSCI 360 Midterm', ' Midterm task for CSCI 360 due on February 19', TO_DATE('02/19/2023', 'MM-DD-YYYY'), 0.25, 0, 2009, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (60, 5, 'CSCI 360 Final Exam', ' Final Exam task for CSCI 360 due on April 18', TO_DATE('04/18/2023', 'MM-DD-YYYY'), 0.5, 0, 2009, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (61, 0, 'CSCI 370 Participation', ' Participation task for CSCI 370 due on January 13', TO_DATE('01/13/2023', 'MM-DD-YYYY'), 0.05, 0, 2010, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (62, 1, 'CSCI 370 Assignment', ' Assignment task for CSCI 370 due on January 26', TO_DATE('01/26/2023', 'MM-DD-YYYY'), 0.1, 0, 2010, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (63, 2, 'CSCI 370 Project', ' Project task for CSCI 370 due on February 11', TO_DATE('02/11/2023', 'MM-DD-YYYY'), 0.15, 0, 2010, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (64, 3, 'CSCI 370 Quiz', ' Quiz task for CSCI 370 due on February 12', TO_DATE('02/12/2023', 'MM-DD-YYYY'), 0.2, 0, 2010, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (65, 4, 'CSCI 370 Midterm', ' Midterm task for CSCI 370 due on March 09', TO_DATE('03/09/2023', 'MM-DD-YYYY'), 0.25, 0, 2010, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (66, 5, 'CSCI 370 Final Exam', ' Final Exam task for CSCI 370 due on April 27', TO_DATE('04/27/2023', 'MM-DD-YYYY'), 0.5, 0, 2010, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (67, 0, 'MATH 123 Participation', ' Participation task for MATH 123 due on January 06', TO_DATE('01/06/2023', 'MM-DD-YYYY'), 0.05, 0, 2011, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (68, 1, 'MATH 123 Assignment', ' Assignment task for MATH 123 due on January 28', TO_DATE('01/28/2023', 'MM-DD-YYYY'), 0.1, 0, 2011, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (69, 2, 'MATH 123 Project', ' Project task for MATH 123 due on January 18', TO_DATE('01/18/2023', 'MM-DD-YYYY'), 0.15, 0, 2011, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (70, 3, 'MATH 123 Quiz', ' Quiz task for MATH 123 due on February 03', TO_DATE('02/03/2023', 'MM-DD-YYYY'), 0.2, 0, 2011, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (71, 4, 'MATH 123 Midterm', ' Midterm task for MATH 123 due on February 11', TO_DATE('02/11/2023', 'MM-DD-YYYY'), 0.25, 0, 2011, NULL, NULL);
INSERT INTO Tasks (taskID, type, name, description, dueDate, weight, isComplete, courseID, studentID, instructorID) VALUES (72, 5, 'MATH 123 Final Exam', ' Final Exam task for MATH 123 due on April 03', TO_DATE('04/03/2023', 'MM-DD-YYYY'), 0.5, 0, 2011, NULL, NULL);


-- 72 STUDENT-TASKS
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1000, 10, 'Personal Task', 'Personal task for Carman Gravel', 0, 0, NULL, 101, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1001, 10, 'Personal Task', 'Personal task for Brent Ladouceur', 0, 0, NULL, 102, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1002, 10, 'Personal Task', 'Personal task for Eddie Stewart', 0, 0, NULL, 103, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1003, 10, 'Personal Task', 'Personal task for Helena Viau', 0, 0, NULL, 104, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1004, 10, 'Personal Task', 'Personal task for Norman Godin', 0, 0, NULL, 105, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1005, 10, 'Personal Task', 'Personal task for Michel Marshall', 0, 0, NULL, 106, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1006, 10, 'Personal Task', 'Personal task for Catherine Cummings', 0, 0, NULL, 107, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1007, 10, 'Personal Task', 'Personal task for Christine Hudson', 0, 0, NULL, 108, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1008, 10, 'Personal Task', 'Personal task for Fred Dick', 0, 0, NULL, 109, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1009, 10, 'Personal Task', 'Personal task for Glenda Forbes', 0, 0, NULL, 110, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1010, 10, 'Personal Task', 'Personal task for William Lowe', 0, 0, NULL, 111, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1011, 10, 'Personal Task', 'Personal task for Jeff Marsh', 0, 0, NULL, 112, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1012, 10, 'Personal Task', 'Personal task for Josephine Donovan', 0, 0, NULL, 113, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1013, 10, 'Personal Task', 'Personal task for Martha Wall', 0, 0, NULL, 114, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1014, 10, 'Personal Task', 'Personal task for Ingrid Rose', 0, 0, NULL, 115, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1015, 10, 'Personal Task', 'Personal task for Pierre Huang', 0, 0, NULL, 116, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1016, 10, 'Personal Task', 'Personal task for Chuck Gervais', 0, 0, NULL, 117, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1017, 10, 'Personal Task', 'Personal task for Brittany Cantin', 0, 0, NULL, 118, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1018, 10, 'Personal Task', 'Personal task for Amber Guay', 0, 0, NULL, 119, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1019, 10, 'Personal Task', 'Personal task for Merle MacKinnon', 0, 0, NULL, 120, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1020, 10, 'Personal Task', 'Personal task for Alan Piche', 0, 0, NULL, 121, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1021, 10, 'Personal Task', 'Personal task for Susanne Theriault', 0, 0, NULL, 122, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1022, 10, 'Personal Task', 'Personal task for Germaine Lacombe', 0, 0, NULL, 123, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1023, 10, 'Personal Task', 'Personal task for Benjamin Talbot', 0, 0, NULL, 124, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1024, 10, 'Personal Task', 'Personal task for Curtis Burns', 0, 0, NULL, 125, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1025, 10, 'Personal Task', 'Personal task for Annette Jacobs', 0, 0, NULL, 126, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1026, 10, 'Personal Task', 'Personal task for Stuart Hughes', 0, 0, NULL, 127, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1027, 10, 'Personal Task', 'Personal task for Tania Charron', 0, 0, NULL, 128, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1028, 10, 'Personal Task', 'Personal task for Jodi James', 0, 0, NULL, 129, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1029, 10, 'Personal Task', 'Personal task for Reginald Bradley', 0, 0, NULL, 130, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1030, 10, 'Personal Task', 'Personal task for Felix McCallum', 0, 0, NULL, 131, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1031, 10, 'Personal Task', 'Personal task for Jean-Guy Gagnon', 0, 0, NULL, 132, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1032, 10, 'Personal Task', 'Personal task for Gayle Doiron', 0, 0, NULL, 133, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1033, 10, 'Personal Task', 'Personal task for Jayne Butler', 0, 0, NULL, 134, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1034, 10, 'Personal Task', 'Personal task for Alain Kelly', 0, 0, NULL, 135, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1035, 10, 'Personal Task', 'Personal task for Jamie Milne', 0, 0, NULL, 136, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1036, 10, 'Personal Task', 'Personal task for Edna Daigle', 0, 0, NULL, 137, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1037, 10, 'Personal Task', 'Personal task for Olivier English', 0, 0, NULL, 138, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1038, 10, 'Personal Task', 'Personal task for Yvette Pilon', 0, 0, NULL, 139, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1039, 10, 'Personal Task', 'Personal task for Rodney Chouinard', 0, 0, NULL, 140, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1040, 10, 'Personal Task', 'Personal task for Gene Davidson', 0, 0, NULL, 141, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1041, 10, 'Personal Task', 'Personal task for Melissa McRae', 0, 0, NULL, 142, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1042, 10, 'Personal Task', 'Personal task for Charmaine Turgeon', 0, 0, NULL, 143, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1043, 10, 'Personal Task', 'Personal task for Lucie Gardner', 0, 0, NULL, 144, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1044, 10, 'Personal Task', 'Personal task for Jeannie Gendron', 0, 0, NULL, 145, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1045, 10, 'Personal Task', 'Personal task for Rosaire Young', 0, 0, NULL, 146, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1046, 10, 'Personal Task', 'Personal task for Agnes Cameron', 0, 0, NULL, 147, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1047, 10, 'Personal Task', 'Personal task for Brendan Maltais', 0, 0, NULL, 148, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1048, 10, 'Personal Task', 'Personal task for Bertha Guillemette', 0, 0, NULL, 149, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1049, 10, 'Personal Task', 'Personal task for Carl Phillips', 0, 0, NULL, 150, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1050, 10, 'Personal Task', 'Personal task for Felix Germain', 0, 0, NULL, 151, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1051, 10, 'Personal Task', 'Personal task for Jordan Mercer', 0, 0, NULL, 152, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1052, 10, 'Personal Task', 'Personal task for Donald Labelle', 0, 0, NULL, 153, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1053, 10, 'Personal Task', 'Personal task for Chas Vaillancourt', 0, 0, NULL, 154, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1054, 10, 'Personal Task', 'Personal task for Victor Pratt', 0, 0, NULL, 155, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1055, 10, 'Personal Task', 'Personal task for Jane Kerr', 0, 0, NULL, 156, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1056, 10, 'Personal Task', 'Personal task for Vicky Levasseur', 0, 0, NULL, 157, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1057, 10, 'Personal Task', 'Personal task for Cheryl Lloyd', 0, 0, NULL, 158, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1058, 10, 'Personal Task', 'Personal task for Grace Chan', 0, 0, NULL, 159, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1059, 10, 'Personal Task', 'Personal task for Brett Schmidt', 0, 0, NULL, 160, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1060, 10, 'Personal Task', 'Personal task for Ginette Sanderson', 0, 0, NULL, 161, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1061, 10, 'Personal Task', 'Personal task for Leona Campbell', 0, 0, NULL, 162, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1062, 10, 'Personal Task', 'Personal task for Aaron Frenette', 0, 0, NULL, 163, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1063, 10, 'Personal Task', 'Personal task for Nadine Gill', 0, 0, NULL, 164, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1064, 10, 'Personal Task', 'Personal task for Jean-Claude Berry', 0, 0, NULL, 165, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1065, 10, 'Personal Task', 'Personal task for Melissa Tait', 0, 0, NULL, 166, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1066, 10, 'Personal Task', 'Personal task for Taylor Beauchemin', 0, 0, NULL, 167, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1067, 10, 'Personal Task', 'Personal task for Donna Gervais', 0, 0, NULL, 168, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1068, 10, 'Personal Task', 'Personal task for Rolland Clement', 0, 0, NULL, 169, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1069, 10, 'Personal Task', 'Personal task for Kristin Dunlop', 0, 0, NULL, 170, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1070, 10, 'Personal Task', 'Personal task for Emma Nielsen', 0, 0, NULL, 171, NULL);
INSERT INTO Tasks (taskID, type, name, description, weight, isComplete, courseID, studentID, instructorID) VALUES (1071, 10, 'Personal Task', 'Personal task for Mark Paul', 0, 0, NULL, 172, NULL);


-- LISTS ALL CONFLICTING DUEDATES 
-- SELECT t.type, t.dueDate, c.courseName, COUNT(DISTINCT sc.studentID) AS affected_students
-- FROM Tasks t
-- JOIN StudentCourses sc ON t.courseID = sc.courseID
-- JOIN Courses c ON t.courseID = c.courseID
-- WHERE t.dueDate IN (
--     SELECT t2.dueDate
--     FROM Tasks t2
--     JOIN StudentCourses sc2 ON t2.courseID = sc2.courseID
--     WHERE t2.courseID = :thisCourse
--     AND sc2.studentID = sc.studentID
-- )
-- AND t.courseID != :thisCourse
-- AND sc.studentID IN (
--     SELECT sc3.studentID
--     FROM StudentCourses sc3
--     WHERE sc3.courseID = :thisCourse
-- )
-- GROUP BY t.type, t.dueDate, c.courseName;


-- GETS NUMBER OF MATCHING DUEDATES 
    -- SELECT COUNT(dueDate) as dd, dueDate
    -- FROM Tasks
    -- GROUP BY dueDate
    -- HAVING COUNT(dueDate) > 1
    -- ORDER BY dueDate