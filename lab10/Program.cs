//ІЛьницький Ростислав, ІП-72,Варіант 11
//1)В класі Student  реалізувати стандартний інтерфейс ICloneable().
//Реалізація методу Clone() повинна виконувати повну (глибоку) копію об‘єкта Student і повертати цю копію
//2)	В класі Person перевизначити метод Equals(object obj) базового класу і визначити операції == і !=
//так, щоб рівність об‘єктів типу Person трактувалась як збіг значень всіх властивостей об‘єктів, а не посилань на об‘экти Person.
//5)	В класі  Student додати ітератор з параметром для перебору іспитів/заліків (об‘єктів типу Examination)
//з оцінкою (балом) більше або рівною заданому значенню.
//11)	В класі Person додати метод, який розраховує та повертає вік людини.

using System;

namespace lab10
{
  internal class Program
  {
    static void SetSomeStudentProperties(Student nik)
    {
        nik.Name = "Nikita";
        nik.SurName = "Ivanov";
        nik.birthDate = 1999;
        nik.LevelOfEducation = Student.Education.Bachelor;
        nik.NumOfRecordBook = 4567890;
    }

    static void AddSomeExams(Student nik)
    {
        Examination[] ListOfExams = new Examination[]
        {
            new Examination(3,"OOP","Mukha I.P.",60,true,new DateTime(2019,1,9)),
            new Examination(3,"Probability Theory","Harko I.I.",75,false,new DateTime(2019,1,15)),
            new Examination(3,"Architecture of computer", "Kogan A.V.",87,true,new DateTime(2019,1,18)) 
        };
        nik.AddExams(ListOfExams);
    }

    static void Task1(Student rost)
    {
        Console.WriteLine("Task1:");
        rost.birthDate= 2000;
        Student nik = (Student)rost.Clone();
        rost.PrintFullInfo();
        Console.WriteLine();
    }

    static void Task2(Student rost)
    {
        Console.WriteLine("Task2:");
        Student nik = (Student)rost.Clone();
        Console.WriteLine(nik == rost);
        Console.WriteLine(nik != rost);
        rost.Name = "Rostik";
        Console.WriteLine(nik == rost);
        Console.WriteLine(nik != rost);
    }

    static void Task5(Student nik)
    {
        Console.WriteLine("Task5:");
        AddSomeExams(nik);
        foreach (Examination currentExam in nik)
        {
            Console.WriteLine(currentExam.ToString());
        }

        Console.WriteLine();
    }

    static void Task11(Student nik)
    {
        Console.WriteLine("Task11:");
        nik.birthDate = 1998;
       Console.Write(nik.calculateAge()); 


    }
    
    public static void Main(string[] args)
    {
        Student vasya = new Student();
        Console.WriteLine(vasya);

        SetSomeStudentProperties(vasya);

       
        Console.WriteLine();

        AddSomeExams(vasya);

        Console.WriteLine(vasya);
        Console.WriteLine();

        vasya.PrintFullInfo();
        Console.WriteLine();
            
        Task1(vasya);
        Task2(vasya);
        Task5(vasya);
        Task11(vasya);

        Console.ReadKey();
    }
  }
}