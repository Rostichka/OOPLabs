using System;
using System.Collections;
using System.Collections.Generic;
using System.Globalization;
using System.Net.Sockets;
using System.Security.Cryptography;

namespace lab10
{
    public class Student : Person, ICloneable, IEnumerable<Examination>
    {
        public Student()
        {
        }
        public enum Education
        {
            Master,
            Bachelor,
            SecondEducation,
            PhD   
        }
        
        public Education LevelOfEducation { get; set; }
        public string Group { get; set; }
       
        public int NumOfRecordBook { get; set; }

        public Examination[] ExamList;
        
        public  double Average
        {
            get
            {
                double res = 0; 
                foreach (var i in ExamList)
                {
                    res += i.GetMark();
                }

                return res / ExamList.Length;
            }    
        }

        public void AddExams(Examination[] examList)
        {
            ExamList = examList;
        }

        public IEnumerator<Examination> GetEnumerator()
        {
            for (int i = 0; i < ExamList.Length; i++)
            {
                 if (ExamList[i].Mark >= 75)
                {
                yield return ExamList[i];
                }
            }
        }
    
        IEnumerator IEnumerable.GetEnumerator()
        {
            return  GetEnumerator();
        }
    
   

        public override string ToString()
        {
            return $"Name: {Name}\n Surname: {SurName}\n Group: {Group} ";
        }

        public object Clone()
        {
            Student studClone = new Student();
            studClone.Name = this.Name;
            studClone.SurName = this.SurName;
            studClone.birthDate = this.birthDate;
            studClone.LevelOfEducation = this.LevelOfEducation;
            studClone.Group = this.Group;
            studClone.NumOfRecordBook = this.NumOfRecordBook;
            foreach (Examination i in this.ExamList)
            {
                studClone.ExamList = ExamList;
            }
            return studClone;
        }

        public override void PrintFullInfo()
        {
            Console.Write($"Name: {Name}\n Surname: {SurName}\n Birth: {birthDate}\n Qualification: {LevelOfEducation}\n" +
                          $"Group: {Group}\n RecordBook: {NumOfRecordBook}\n Exams:\n");
                foreach (Examination i in ExamList)
                {
                    Console.WriteLine(i);
                }
            Console.WriteLine($"Average Mark: {Average}");
        }
    }
}