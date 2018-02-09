/** 
 * The operating system class.
 * 
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2014-2018, Embedded Team, Sergey Baigudin
 * @license   http://embedded.team/license/
 */
#ifndef SYSTEM_SYSTEM_HPP_
#define SYSTEM_SYSTEM_HPP_

#include "system.Object.hpp"
#include "api.System.hpp"
#include "kernel.Kernel.hpp"
#include "Configuration.hpp"

namespace system
{
    class System : public ::system::Object, public ::api::System
    {
        typedef ::system::System Self;    
        typedef ::system::Object Parent;    
      
    public:
    
        /** 
         * Constructor.
         */    
        System();
        
        /** 
         * Destructor.
         */
        virtual ~System();
        
        /**
         * Tests if this object has been constructed.
         *
         * @return true if object has been constructed successfully.
         */    
        virtual bool isConstructed() const;
        
        /**
         * Returns the operating system heap memory.
         *
         * @return the heap memory.
         */
        virtual ::api::Heap& getHeap() const;
        
        /**
         * Returns running time of the operating system in milliseconds.
         *
         * @return time in milliseconds.
         */
        virtual int64 getTimeMs() const;
           
        /**
         * Returns running time of the operating system in nanoseconds.
         *
         * @return time in nanoseconds.
         */
        virtual int64 getTimeNs() const;
        
        /**
         * Terminates the operating system execution.
         */
        virtual void terminate() const;                   
    
        /** 
         * Returns the operating system syscall interface.
         *
         * @return the operating system syscall interface.
         */      
        static ::api::System& call();
        
    private:
    
        enum Error
        {
            /**
             * No errors occurred.
             */
            SYSER_OK,

            /**
             * Error of a user program occurred.
             */            
            SYSER_USER_TERMINATION,
                    
            /**
             * Error of the operating system syscall calling.
             */
            SYSER_SYSCALL_CALLED,
            
            /**
             * Error of a no strinct MISRA C++ function calling.
             */
            SYSER_NO_MISRA_FUNCTION_CALLED

        };
    
        /**
         * Constructs this object.
         *
         * @return true if object has been constructed successfully.     
         */    
        bool construct();
        
        /**
         * Terminates the operating system execution.
         *
         * @param error a termination status code.
         */
        static void terminate(Error error);
    
        /**
         * The operatin system interface.
         */
        static ::api::System* system_;
        
        /**    
         * Configuration of the operating system .    
         *
         * NOTE: the variable must be the first, as it must be initialized first.
         */
        const ::Configuration config_;        
        
        /**
         * The operating system kernel.
         */
        ::kernel::Kernel kernel_;      
        
    };
}
#endif // SYSTEM_SYSTEM_HPP_
