#include <SFML/Graphics.hpp>
#include <array>

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Sunset Lake");
    window.setFramerateLimit(60);

    const std::array<sf::Vector2f, 22> starPositions = {{
        {55, 65}, {125, 112}, {205, 48}, {275, 130}, {340, 72}, {470, 55},
        {545, 115}, {635, 48}, {740, 94}, {90, 205}, {190, 178}, {285, 224},
        {500, 190}, {615, 215}, {725, 178}, {40, 275}, {165, 255}, {555, 260},
        {700, 270}, {315, 40}, {680, 135}, {430, 150}
    }};

    sf::CircleShape sun(104.f);
    sun.setFillColor(sf::Color(255, 181, 112));
    sun.setPosition({348.f, 172.f});

    sf::RectangleShape lake({800.f, 210.f});
    lake.setPosition({0.f, 390.f});
    lake.setFillColor(sf::Color(23, 32, 59));

    sf::ConvexShape farMountains;
    farMountains.setPointCount(7);
    farMountains.setPoint(0, {0.f, 390.f});
    farMountains.setPoint(1, {130.f, 275.f});
    farMountains.setPoint(2, {275.f, 398.f});
    farMountains.setPoint(3, {450.f, 250.f});
    farMountains.setPoint(4, {625.f, 395.f});
    farMountains.setPoint(5, {735.f, 300.f});
    farMountains.setPoint(6, {800.f, 355.f});
    farMountains.setFillColor(sf::Color(83, 67, 105));

    sf::ConvexShape nearMountains;
    nearMountains.setPointCount(7);
    nearMountains.setPoint(0, {0.f, 425.f});
    nearMountains.setPoint(1, {170.f, 345.f});
    nearMountains.setPoint(2, {310.f, 430.f});
    nearMountains.setPoint(3, {520.f, 330.f});
    nearMountains.setPoint(4, {660.f, 420.f});
    nearMountains.setPoint(5, {770.f, 350.f});
    nearMountains.setPoint(6, {800.f, 380.f});
    nearMountains.setFillColor(sf::Color(43, 48, 77));

    const std::array<float, 7> reflectionWidths = {170.f, 120.f, 205.f, 145.f, 185.f, 110.f, 155.f};
    const std::array<sf::Color, 3> reflectionColors = {
        sf::Color(255, 181, 112, 170), sf::Color(220, 125, 119, 150), sf::Color(105, 121, 161, 130)
    };

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color(17, 23, 43));

        sf::RectangleShape dusk({800.f, 155.f});
        dusk.setPosition({0.f, 235.f});
        dusk.setFillColor(sf::Color(49, 35, 63));
        window.draw(dusk);

        sf::RectangleShape horizonGlow({800.f, 48.f});
        horizonGlow.setPosition({0.f, 342.f});
        horizonGlow.setFillColor(sf::Color(111, 57, 76));
        window.draw(horizonGlow);

        for (std::size_t i = 0; i < starPositions.size(); ++i) {
            sf::CircleShape star(i % 4 == 0 ? 2.4f : 1.5f);
            star.setFillColor(i % 4 == 0 ? sf::Color(255, 226, 190) : sf::Color(197, 204, 226));
            star.setPosition(starPositions[i]);
            window.draw(star);
        }

        window.draw(sun);
        window.draw(lake);
        window.draw(farMountains);
        window.draw(nearMountains);

        for (std::size_t i = 0; i < reflectionWidths.size(); ++i) {
            sf::RectangleShape reflection({reflectionWidths[i], 3.f});
            reflection.setPosition({400.f - reflectionWidths[i] / 2.f, 445.f + static_cast<float>(i) * 20.f});
            reflection.setFillColor(reflectionColors[i % reflectionColors.size()]);
            window.draw(reflection);
        }

        sf::RectangleShape shore({800.f, 28.f});
        shore.setPosition({0.f, 572.f});
        shore.setFillColor(sf::Color(13, 19, 36));
        window.draw(shore);

        window.display();
    }

    return 0;
}