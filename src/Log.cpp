#include "Log.h"
#include <string>


// !
#define SERIALIZED_LOG_TEMPLATE (std::string)\
        "\t\t{\n " +\
            "\t\t\t\"type\":\"PLACE_FOR_TYPE\",\n" + \
            "\t\t\t\"time\":\"PLACE_FOR_TIME\",\n" + \
            "\t\t\t\"file\":\"PLACE_FOR_FILE\",\n" + \
            "\t\t\t\"function\":\"PLACE_FOR_FUNCTION\",\n" + \
            "\t\t\t\"message\":\"PLACE_FOR_MESSAGE\"\n" + \
        "\t\t}" \
// !

std::string Log::Replace_In_String(std::string& s, const std::string& toReplace, const std::string& replaceWith){
    std::size_t pos = s.find(toReplace);
    if (pos == std::string::npos){
        return s;
    } 

    return s.replace(pos, toReplace.length(), replaceWith);
}


        Log::Log(TYPE_OF_LOG type_in,
            std::string time_in,
            std::string file_in,
            std::string function_in,
            std::string message_in):
                m_type(type_in),
                m_time(time_in),
                m_file(file_in),
                m_function(function_in),
                m_message(message_in){};
        Log::Log(std::string type_in,
            std::string time_in,
            std::string file_in,
            std::string function_in,
            std::string message_in):
                m_type(StringToType(type_in)),
                m_time(time_in),
                m_file(file_in),
                m_function(function_in),
                m_message(message_in){};

        std::string Log::Serialize(){
            std::string serialized_log = SERIALIZED_LOG_TEMPLATE;
            Replace_In_String(serialized_log, "PLACE_FOR_TYPE", TypeToString(m_type));
            Replace_In_String(serialized_log, "PLACE_FOR_TIME", m_time);
            Replace_In_String(serialized_log, "PLACE_FOR_FILE", m_file);           
            Replace_In_String(serialized_log, "PLACE_FOR_FUNCTION", m_function); 
            Replace_In_String(serialized_log, "PLACE_FOR_MESSAGE", m_message);
            return serialized_log;
        }
        std::string Log::TypeToString(TYPE_OF_LOG type){
            switch (type) {                
                case t_VERBOSE:{
                    return "VERBOSE";
                }
                case t_FATAL:{
                    return "FATAL";
                }
                case t_ERROR:{
                    return "ERROR";
                }  
                case t_DEBUG:{
                    return "DEBUG";
                }
                default: {
                    return "NO TYPE";
                }
            }
        }
        TYPE_OF_LOG Log::StringToType(std::string type)
        {            
            if(type=="VERBOSE"){
                return t_VERBOSE;
            }
            if(type=="FATAL"){
                return t_FATAL;
            }
            if(type=="ERROR"){
                return t_ERROR;
            }  
            if(type=="DEBUG"){
                return t_DEBUG;
            }
            return t_WRONG_TYPE;
        }


        TYPE_OF_LOG Log::GetType(){
            return m_type;
        }
        std::string Log::GetTime(){
            return m_time;
        }
        std::string Log::GetFile(){
            return m_file;
        }
        std::string Log::GetMessage(){
            return m_message;
        }
        std::string Log::GetFunction(){
            return m_function;
        }
