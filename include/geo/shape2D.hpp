#ifndef SHAPE2D_HPP
#define SHAPE2D_HPP

#include "glm/vec2.hpp"
#include "ini/serializable.hpp"
#include "geo/aabb2D.hpp"

namespace geo
{
    class shape2D : public ini::serializable
    {
    public:
        shape2D(const glm::vec2 &centroid = glm::vec2(0.f));

        virtual void translate(const glm::vec2 &dpos);
        void pos(const glm::vec2 &pos);

        virtual glm::vec2 support_point(const glm::vec2 &direction) const = 0;
        virtual bool contains_point(const glm::vec2 &p) const = 0;
        virtual bool contains_origin() const = 0;

        virtual aabb2D bounding_box() const = 0;
        virtual glm::vec2 closest_direction_from(const glm::vec2 &p) const = 0;

        const glm::vec2 &centroid() const;
        virtual float area() const = 0;
        virtual float inertia() const = 0;

        virtual void rotate(float dangle);
        void rotation(float angle);
        float rotation() const;

    protected:
        glm::vec2 m_centroid;
        float m_angle = 0.f;
    };
}

#endif