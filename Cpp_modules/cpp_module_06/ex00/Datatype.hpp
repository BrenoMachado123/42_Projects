#ifndef DATATYPE_HPP
# define DATATYPE_HPP


class Datatype {
	private:
		//the string that will be converted:
		std::string _cstring;
	public:
		Datatype();
		Datatype(const Convert& other);
		Datatype& operator=(const Convert& other);
		~Datatype();

		//conversions to implement:
		void	ConvertChar;
		void	ConvertInt;
		void	ConvertDouble;
		void	ConvertFloat;
}




#endif
