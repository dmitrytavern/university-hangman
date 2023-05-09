import { defineConfig } from "vitepress";

export const nav = [
  { text: "Головна", link: "/" },
  { text: "Посібник", link: "/guide/" },
];

export const sidebar = {
  "/guide/": [
    {
      text: "Введение",
      items: [{ text: "Що таке Hangman?", link: "/guide/introduction/what-is-hangman" }],
    },
    {
      text: "Конфигурация",
      items: [
        { text: "Вступ", link: "/guide/installation/" },
        { text: "Налаштування Qt", link: "/guide/installation/qt" },
        { text: "Правила роботи Git", link: "/guide/installation/git" },
        { text: "Правила найменування", link: "/guide/installation/conventional-naming.md" },
        { text: "Стиль коду", link: "/guide/installation/code-style" },
        { text: "Ведення гілок", link: "/guide/installation/conventional-branchs" },
        { text: "Ведення комітів", link: "/guide/installation/conventional-commits" },
      ],
    },
    {
      text: "Скрам",
      items: [
        { text: "Усі спринти", link: "/guide/iterations/" },
        { text: "Спринт 1", link: "/guide/iterations/sprint-1" },
        { text: "Спринт 2", link: "/guide/iterations/sprint-2" },
        { text: "Спринт 3", link: "/guide/iterations/sprint-3" },
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
