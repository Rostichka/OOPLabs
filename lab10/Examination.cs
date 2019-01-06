using System;

namespace lab10
{
    public class Examination
    {
        public int NumOfSemester { get; protected set; }
        public string Subject { get; protected set; }
        public string TeachersName { get; protected set; }
        public int Mark { get; protected set; }
        public bool IsDiff { get; protected set; }
        public DateTime DateOfExam { get; protected set; }

        public int GetMark()
        {
            return Mark;
        }
        

        public Examination()
        {
            NumOfSemester = 3;
            Subject = "OOP";
            TeachersName = " Mukha I.P.";
            Mark = 60;
            IsDiff = true;
            DateOfExam = new DateTime(2019,1,9);
        }

        public Examination(int numOfSemester, string subject, string teachersName, 
            int mark, bool isDiff, DateTime dateOfExam)
        {
            NumOfSemester = numOfSemester;
            Subject = subject;
            TeachersName = teachersName;
            Mark = mark;
            IsDiff = isDiff;
            DateOfExam = dateOfExam;
        }

        public override string ToString()
        {
            return String.Format("Subject: {0}, Teacher: {1}, Mark: {2}", Subject, TeachersName, Mark);
        }
    }
}