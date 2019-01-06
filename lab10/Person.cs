using System;

namespace lab10
{
    public class Person
    {
        public string Name;
        public string SurName;

        private DateTime _dateOfBirth;

        public int birthDate
        {
            get { return _dateOfBirth.Year; }
            set { _dateOfBirth = new DateTime(value, _dateOfBirth.Month, _dateOfBirth.Day); }
        }

        public Person()
        {
            Name = "Rostik";
            SurName = "Ilnytskyi";
            _dateOfBirth = new DateTime(2000, 6, 20);
        }

        public Person(string name, string surName, DateTime dateOfBirth)
        {
            Name = name;
            SurName = surName;
            _dateOfBirth = dateOfBirth;
        }

        public virtual void PrintFullInfo()
        {
            Console.Write($"Name is {Name}\n" +
            $"Surname is {SurName}\n" +
            $"Date of birth is {_dateOfBirth.ToShortDateString()}");     
        }

        public override bool Equals(object o)
        {
            var person = o as Person;
            if (person == null)
            {
                return false;
            }
            return this == person;
        }

        public static bool operator ==(Person n, Person r)
        {
            if ((n.Name == r.Name) && (n.SurName == r.SurName) && (n._dateOfBirth == r._dateOfBirth))
                return true;
            return false;
        }

        public static bool operator !=(Person n, Person r)
        {
            if ((n.Name != r.Name) || (n.SurName != r.SurName) || (n._dateOfBirth != r._dateOfBirth))
                return true;
            return false;
        }

        public int calculateAge()
        {
            DateTime now = DateTime.Now;
            int pYear = birthDate,
                pMonth = _dateOfBirth.Month,
                pDay = _dateOfBirth.Day;
            return now.Year - pYear - (pMonth > now.Month || (pMonth == now.Month && pDay > now.Day) ? 1 : 0);
        }
    }
}