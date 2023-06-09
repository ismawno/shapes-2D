#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "geo/shape2D.hpp"

namespace geo
{
    class circle : public shape2D
    {
    public:
        circle(float radius = 1.f);
        circle(const glm::vec2 &pos, float radius = 1.f);
        circle(const glm::vec2 &pos, float radius, float angle);

        glm::vec2 support_point(const glm::vec2 &direction) const override;
        bool contains_point(const glm::vec2 &p) const override;
        bool contains_origin() const override;

        float area() const override;
        float inertia() const override;

        aabb2D bounding_box() const override;
        glm::vec2 closest_direction_from(const glm::vec2 &p) const override;

        float radius() const;
        void radius(float radius);

        void serialize(ini::serializer &out) const override;
        void deserialize(ini::deserializer &in) override;

    private:
        float m_radius;
    };
}

#endif