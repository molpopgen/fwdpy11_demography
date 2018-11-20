//This will be moved into fwdpy11

#include <cstdint>
#include <functional>
#include <fwdpy11/types/SlocusPop.hpp>
#include <fwdpy11/types/MlocusPop.hpp>

namespace fwdpy11
{
    using mating_recorder = std::function<void(
        const std::size_t mate, const DiploidMetadata& offspring_metadata)>;

    struct reproduction
    {
        virtual void record_mate(const SlocusPop& pop,
                                 const std::size_t individual,
                                 const mating_recorder& mr)
            = 0;
        virtual void record_mate(const MlocusPop& pop,
                                 const std::size_t individual,
                                 const mating_recorder& mr)
            = 0;
    };
} // namespace fwdpy11
