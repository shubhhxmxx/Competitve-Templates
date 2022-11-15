// Using std::unique
    ip = std::unique(v.begin(), v.begin() + 12);
    // Now v becomes {1 3 10 1 3 7 8 * * * * *}
    // * means undefined

    // Resizing the vector so as to remove the undefined terms
    v.resize(std::distance(v.begin(), ip));
