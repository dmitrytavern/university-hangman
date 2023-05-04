import { defineConfig } from "vitepress";

export const nav = [
  { text: "Головна", link: "/" },
  { text: "Посібник", link: "/guide/" },
];

export const sidebar = {
  "/guide/": [
    {
      text: "Конфигурация",
      items: [
        { text: "Налаштування Qt", link: "/guide/installation/qt" },
        { text: "Правила роботи Git", link: "/guide/installation/git" },
        { text: "Стиль коду", link: "/guide/installation/code-style" },
        { text: "Ведення гілок", link: "/guide/installation/conventional-branchs" },
        { text: "Ведення комітів", link: "/guide/installation/conventional-commits" },
      ],
    },
  ],
};

export default defineConfig({
  base: "/university-hangman",
  title: "Шибениця",
  themeConfig: {
    nav,
    sidebar,
    socialLinks: [{ icon: "github", link: "https://github.com/dmitrytavern/university-hangman" }],
  },
});
