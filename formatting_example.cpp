#include "a.hpp"
#include "b.hpp"
#include "z.hpp"

class formatting_example
{
private:
        float state;

public:
        formatting_example();
        virtual ~formatting_example();

        // Breaking strings
        static constexpr NAME
            = "veryveryveryveryveryveryveryveryveryveryveryvery long name";

        static struct structure {
                int state;
        };
};

formatting_example::formatting_example()
{
        // Automated intendation and linebreaking
        if (error) {
                panic();

        } else if (some_condition
                   || very_long_function(
                       aligator,
                       cargo,
                       airplane,
                       std::make_unique<struct s>({ 1, 2, 3, 4, 5, 6 }))) {
                a = b + c;
                struct s {
                        int real, int cmplx
                };
        } else
                goto spaghetti;

        for (size_t i = 0; i < count; i++) {
                i++;
        }

        return CONST;
}
