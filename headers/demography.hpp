//This will be moved into fwdpy11

#include <cstdint>
#include <functional>
#include <fwdpy11/types/SlocusPop.hpp>
#include <fwdpy11/types/MlocusPop.hpp>

namespace fwdpy11
{
    /// A callable type with this signature
    /// will be made available to reproduction objects.
    /// The calling environment is repsonsible for tracking
    /// the index of the first parent ("individual" passed
    /// to reproduction::record_mate.  A non-const
    /// DiploidMetaData is to be passed in, and the following
    /// fields may, optionally, be filled:
    /// deme
    /// sex
    /// geography
    /// e
    /// Others?
    using mating_recorder = std::function<void(
        const std::size_t mate, DiploidMetadata& offspring_metadata)>;

    DiploidMetadata
    make_diploid_metadata()
    /// DiploidMetadata does not have a constructor,
    /// which allows it to be used as a numpy dtype.
    /// However, the lack of constructor is inconvenient
    /// for other reasons. This function returns something
    /// guaranteed to be sensibly initialized.
    /// TODO: move to fwdpy11/types/Diploid.hpp
    {
        double g = 0.;         // Genetic value
        double e = 0.;         // Random component of trait value
        double w = 0.;         // Fitness
        std::size_t label = 0; // Index of individual in pop container
        std::uint32_t deme = 0;
        std::int32_t sex = 0;
        return DiploidMetadata{ g,        e,    w,   { 0., 0., 0. }, label,
                                { 0, 0 }, deme, sex, { -1, -1 } };
    }

    struct reproduction
    /// The C++ side of an abstract base class
    /// representing the API for reproduction.
    /// If a derived class wants to support both population
    /// types, the sensible thing is likely to dispatch
    /// the operations to a member template function.
    /// Otherwise, the overloads can simply throw 
    /// exceptions for the type that is not supported.
    /// NOTE: it may be sufficient to pass in the individual
    /// plus its metadata, thus not needing the entire population?
    {
        virtual void record_mate(const SlocusPop& pop,
                                 const std::size_t individual,
                                 const mating_recorder& mr)
            = 0;
        virtual void record_mate(const MlocusPop& pop,
                                 const std::size_t individual,
                                 const mating_recorder& mr)
            = 0;
        virtual void update(const SlocusPop& pop) = 0;
        virtual void update(const MlocusPop& pop) = 0;
    };
} // namespace fwdpy11
