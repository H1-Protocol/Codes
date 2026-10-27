#include <SFML/Graphics.hpp>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <dwmapi.h>
#endif

#include <array>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

struct Button {
    std::string label;
    sf::RectangleShape shape;
    sf::Color color;

    Button(const std::string& text, const sf::Vector2f& size, const sf::Vector2f& position, sf::Color fill)
        : label(text), shape(size), color(fill) {
        shape.setPosition(position);
    }
};

std::string formatNumber(double number) {
    if (std::abs(number) < 0.0000000001)
        number = 0.0;

    std::ostringstream output;
    output << std::setprecision(11) << number;
    return output.str();
}

int main() {
    sf::RenderWindow window(
        sf::VideoMode({420, 650}),
        "Calculator",
        sf::Style::Titlebar | sf::Style::Close
    );
    window.setFramerateLimit(60);

#ifdef _WIN32
    const BOOL useSystemDarkMode = TRUE;
    DwmSetWindowAttribute(
        window.getNativeHandle(),
        DWMWA_USE_IMMERSIVE_DARK_MODE,
        &useSystemDarkMode,
        sizeof(useSystemDarkMode)
    );
#endif

    sf::Image appIcon;
    if (appIcon.loadFromFile("assets/calculator-logo.png"))
        window.setIcon(appIcon);

    sf::Font font;
    if (!font.openFromFile("assets/tuffy.ttf"))
        return 1;

    const sf::Color background(18, 22, 32);
    const sf::Color panelColor(29, 35, 49);
    const sf::Color numberColor(40, 47, 63);
    const sf::Color functionColor(57, 67, 87);
    const sf::Color operatorColor(51, 91, 113);
    const sf::Color equalsColor(41, 181, 151);
    const sf::Color white(239, 243, 250);
    const sf::Color muted(157, 169, 190);

    std::vector<Button> buttons;
    const std::array<std::string, 20> labels = {
        "AC", "DEL", "%", "/",
        "7", "8", "9", "*",
        "4", "5", "6", "-",
        "1", "2", "3", "+",
        "+/-", "0", ".", "="
    };

    constexpr float buttonWidth = 86.f;
    constexpr float buttonHeight = 70.f;
    constexpr float gap = 10.f;
    constexpr float left = 24.f;
    constexpr float top = 210.f;

    for (std::size_t i = 0; i < labels.size(); ++i) {
        const std::string& label = labels[i];
        sf::Color color = numberColor;

        if (label == "AC" || label == "DEL" || label == "%" || label == "+/-")
            color = functionColor;
        else if (label == "/" || label == "*" || label == "-" || label == "+")
            color = operatorColor;
        else if (label == "=")
            color = equalsColor;

        const float x = left + static_cast<float>(i % 4) * (buttonWidth + gap);
        const float y = top + static_cast<float>(i / 4) * (buttonHeight + gap);
        buttons.emplace_back(label, sf::Vector2f(buttonWidth, buttonHeight), sf::Vector2f(x, y), color);
    }

    sf::RectangleShape displayPanel({372.f, 125.f});
    displayPanel.setPosition({24.f, 58.f});
    displayPanel.setFillColor(panelColor);

    std::string display = "0";
    std::string expression;
    double storedNumber = 0.0;
    char pendingOperation = '\0';
    bool startNewNumber = true;
    bool hasError = false;

    auto resetCalculator = [&]() {
        display = "0";
        expression.clear();
        storedNumber = 0.0;
        pendingOperation = '\0';
        startNewNumber = true;
        hasError = false;
    };

    auto calculate = [](double leftNumber, double rightNumber, char operation, double& result) {
        switch (operation) {
            case '+': result = leftNumber + rightNumber; return true;
            case '-': result = leftNumber - rightNumber; return true;
            case '*': result = leftNumber * rightNumber; return true;
            case '/':
                if (rightNumber == 0.0)
                    return false;
                result = leftNumber / rightNumber;
                return true;
            default:
                result = rightNumber;
                return true;
        }
    };

    auto pressButton = [&](const std::string& key) {
        if (key == "AC") {
            resetCalculator();
            return;
        }

        if (hasError) {
            if (key == "DEL") {
                resetCalculator();
                return;
            }
            if (key.size() == 1 && (std::isdigit(static_cast<unsigned char>(key[0])) || key == "."))
                resetCalculator();
            else
                return;
        }

        if (key.size() == 1 && std::isdigit(static_cast<unsigned char>(key[0]))) {
            if (startNewNumber) {
                display = key;
                startNewNumber = false;
            } else if (display == "0") {
                display = key;
            } else if (display.size() < 14) {
                display += key;
            }
            return;
        }

        if (key == ".") {
            if (startNewNumber) {
                display = "0.";
                startNewNumber = false;
            } else if (display.find('.') == std::string::npos) {
                display += '.';
            }
            return;
        }

        if (key == "DEL") {
            if (!startNewNumber && !display.empty()) {
                display.pop_back();
                if (display.empty() || display == "-")
                    display = "0";
            }
            return;
        }

        if (key == "+/-") {
            if (display != "0") {
                if (!display.empty() && display[0] == '-')
                    display.erase(0, 1);
                else
                    display.insert(0, "-");
            }
            return;
        }

        if (key == "%") {
            display = formatNumber(std::stod(display) / 100.0);
            startNewNumber = true;
            return;
        }

        if (key == "=" && pendingOperation != '\0') {
            const double rightNumber = std::stod(display);
            double result = 0.0;
            const bool success = calculate(storedNumber, rightNumber, pendingOperation, result);
            expression = formatNumber(storedNumber) + " " + pendingOperation + " " + formatNumber(rightNumber) + " =";
            if (success) {
                display = formatNumber(result);
            } else {
                display = "Error";
                hasError = true;
            }
            pendingOperation = '\0';
            startNewNumber = true;
            return;
        }

        if (key == "+" || key == "-" || key == "*" || key == "/") {
            if (pendingOperation != '\0' && !startNewNumber) {
                double result = 0.0;
                if (!calculate(storedNumber, std::stod(display), pendingOperation, result)) {
                    display = "Error";
                    hasError = true;
                    pendingOperation = '\0';
                    return;
                }
                display = formatNumber(result);
            }

            storedNumber = std::stod(display);
            pendingOperation = key[0];
            expression = display + " " + key;
            startNewNumber = true;
        }
    };

    while (window.isOpen()) {
        while (const auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* click = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (click->button == sf::Mouse::Button::Left) {
                    const sf::Vector2f mousePosition = window.mapPixelToCoords(click->position);
                    for (const Button& button : buttons) {
                        if (button.shape.getGlobalBounds().contains(mousePosition)) {
                            pressButton(button.label);
                            break;
                        }
                    }
                }
            }
        }

        const sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
        window.clear(background);

        sf::Text title(font);
        title.setString("CALCULATOR");
        title.setCharacterSize(16);
        title.setFillColor(muted);
        title.setPosition({25.f, 22.f});
        window.draw(title);

        window.draw(displayPanel);

        sf::Text expressionText(font);
        expressionText.setString(expression);
        expressionText.setCharacterSize(18);
        expressionText.setFillColor(muted);
        expressionText.setPosition({43.f, 76.f});
        window.draw(expressionText);

        sf::Text displayText(font);
        displayText.setString(display);
        displayText.setCharacterSize(display.size() > 11 ? 30 : 42);
        displayText.setFillColor(white);
        const sf::FloatRect displayBounds = displayText.getLocalBounds();
        displayText.setPosition({375.f - displayBounds.size.x - displayBounds.position.x, 112.f});
        window.draw(displayText);

        for (const Button& button : buttons) {
            sf::RectangleShape buttonShape = button.shape;
            buttonShape.setFillColor(button.color);
            if (button.shape.getGlobalBounds().contains(mousePosition)) {
                buttonShape.setFillColor(sf::Color(
                    static_cast<std::uint8_t>(std::min(255, button.color.r + 18)),
                    static_cast<std::uint8_t>(std::min(255, button.color.g + 18)),
                    static_cast<std::uint8_t>(std::min(255, button.color.b + 18))
                ));
            }
            window.draw(buttonShape);

            sf::Text label(font);
            label.setString(button.label);
            label.setCharacterSize(button.label.size() > 2 ? 20 : 25);
            label.setFillColor(white);
            const sf::FloatRect labelBounds = label.getLocalBounds();
            label.setOrigin({
                labelBounds.position.x + labelBounds.size.x / 2.f,
                labelBounds.position.y + labelBounds.size.y / 2.f
            });
            label.setPosition({
                button.shape.getPosition().x + buttonWidth / 2.f,
                button.shape.getPosition().y + buttonHeight / 2.f
            });
            window.draw(label);
        }

        window.display();
    }

    return 0;
}